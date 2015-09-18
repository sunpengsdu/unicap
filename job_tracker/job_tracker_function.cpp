/*
 *Copyright 2015 NTU (http://www.ntu.edu.sg/)
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
*/
#include "./job_tracker_function.h"

namespace ntu {
namespace cap {

std::thread start_job_tracker(int64_t thread_num) {

    JobTrackerServer::singleton().set_port(NodeInfo::singleton()._master_port);
    JobTrackerServer::singleton().set_thread_num(thread_num);
    auto server_thread = JobTrackerServer::singleton().start();

    while(NodeInfo::singleton()._ready_task_tracker_number
            != NodeInfo::singleton()._task_tracker_number
            || NodeInfo::singleton()._ready_task_tracker_number == 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    JobTrackerServer::singleton().create_task_tracker_client();
    JobTrackerServer::singleton().check_client_task_tracker();

    return server_thread;
}

int64_t create_table(const std::string& table_name,
                     const int64_t shard_num) {

    Table new_table(table_name, shard_num);
    new_table.allocate_shard();

    if (StorageInfo::singleton()._table_info.find(table_name)
            != StorageInfo::singleton()._table_info.end()) {
        LOG(FATAL) << "TABLE ALREADY EXISTS !";
    }

    StorageInfo::singleton()._table_info[table_name] = new_table;

    for (auto i : NodeInfo::singleton()._client_task_tracker) {
        i.second->open_transport();
        i.second->method()->create_table(new_table._table_property);
        i.second->close_transport();
    }

    DLOG(INFO) << "CREATE TABLE " << table_name;
    return 1;
}

int64_t create_table(const std::string& table_name,
                     const int64_t shard_num,
                     const KeyPartition& partition) {

    Table new_table(table_name, shard_num, partition);
    new_table.allocate_shard();

    if (StorageInfo::singleton()._table_info.find(table_name)
            != StorageInfo::singleton()._table_info.end()) {
        LOG(FATAL) << "TABLE ALREADY EXISTS !";
    }

    StorageInfo::singleton()._table_info[table_name] = new_table;

    for (auto i : NodeInfo::singleton()._client_task_tracker) {
        i.second->open_transport();
        i.second->method()->create_table(new_table._table_property);
        i.second->close_transport();
    }

    DLOG(INFO) << "CREATE TABLE " << table_name;
    return 1;
}

int64_t create_table(const std::string& table_name,
                     const Table& base_table) {

    Table new_table(table_name, base_table);

    if (StorageInfo::singleton()._table_info.find(table_name)
            != StorageInfo::singleton()._table_info.end()) {
        LOG(FATAL) << "TABLE ALREADY EXISTS !";
    }

    StorageInfo::singleton()._table_info[table_name] = new_table;

    for (auto i : NodeInfo::singleton()._client_task_tracker) {
        i.second->open_transport();
        i.second->method()->create_table(new_table._table_property);
        i.second->close_transport();
    }

    DLOG(INFO) << "CREATE TABLE " << table_name;
    return 1;
}

int64_t create_cf(const std::string& table_name,
                  const std::string& cf_name,
                  const StorageType::type cf_type) {

    ColumnFamily new_cf(cf_name, cf_type);

    for (auto& exist_cf : StorageInfo::singleton()._cf_info[table_name]) {
        if (exist_cf.first == cf_name) {
            LOG(FATAL) << "CF ALREADY EXISTS !";
        }
    }

    StorageInfo::singleton()._cf_info[table_name][cf_name] = new_cf;

    //for (auto i : NodeInfo)

    for (auto i : NodeInfo::singleton()._client_task_tracker) {
        i.second->open_transport();
        i.second->method()->create_cf(table_name, new_cf._cf_property);
        i.second->close_transport();
    }

    DLOG(INFO) << "CREATE CF " << cf_name << " FOR TABLE " << table_name;
    return 1;
}

int64_t load_file_regular(const std::vector<std::string>& path,
                            const std::vector<int64_t>& size,
                            const std::string& table_name,
                            const std::string& cf_name,
                            const int64_t block_size,
                            std::vector<std::vector<std::pair<std::string, int64_t>>>& full_chuncks) {
    std::vector<std::tuple<std::string, int64_t, int64_t>> free_chuncks;
    CHECK_EQ(path.size(), size.size());
    int64_t chunck_num = 0;
    int64_t last_chunck_size = 0;
    std::vector<std::pair<std::string, int64_t>> new_node;

    for (uint64_t i = 0; i < path.size(); ++i) {
        //std::cout << path[i] << "\n";
        chunck_num = ceil(size[i]/float(block_size));
        for (int64_t j = 0; j < (chunck_num - 1); ++j) {
            new_node.clear();
            new_node.push_back(std::make_pair(path[i], j));
            full_chuncks.push_back(new_node);
        }
        last_chunck_size = size[i] - block_size * (chunck_num - 1);
        if ((float(last_chunck_size) / block_size) > 0.7) {
            new_node.clear();
            new_node.push_back(std::make_pair(path[i], chunck_num - 1));
            full_chuncks.push_back(new_node);
        } else {
            free_chuncks.push_back(std::make_tuple(path[i], chunck_num - 1, last_chunck_size));
        }
    }

    std::vector<uint64_t> merged_id;
    std::vector<std::pair<std::string, int64_t>> new_chunck;
    while(free_chuncks.size() > 0) {
       //std::cout << free_chuncks.size() << "\n";
        merged_id.clear();
        new_chunck.clear();
        int64_t first_ck_size = std::get<2>(free_chuncks[0]);
        int64_t target_ck_size = 0;

        for (uint64_t i = 1; i < free_chuncks.size(); ++i) {
            target_ck_size = std::get<2>(free_chuncks[i]);
            if ((first_ck_size + target_ck_size) < (1.2 * block_size)) {
                merged_id.push_back(i);
                first_ck_size += target_ck_size;
            }
            if (i > 50) {
                break;
            }
        }

        new_chunck.push_back(std::make_pair(std::get<0>(free_chuncks[0]),
                                        std::get<1>(free_chuncks[0])));

        for (auto i = int64_t(merged_id.size()) - 1; i >= 0; --i) {
            new_chunck.push_back(std::make_pair(std::get<0>(free_chuncks[merged_id[i]]),
                                                    std::get<1>(free_chuncks[merged_id[i]])));
            free_chuncks.erase(free_chuncks.begin() + merged_id[i]);
        }
        free_chuncks.erase(free_chuncks.begin());

        full_chuncks.push_back(new_chunck);
    }
    return 1;
}

int64_t load_local_file_regular(const std::vector<std::string>& path,
                    const std::vector<int64_t>& size,
                    const std::string& table_name,
                    const std::string& cf_name,
                    const int64_t block_size) {

    std::vector<std::vector<std::pair<std::string, int64_t>>> chuncks;

    load_file_regular(path, size, table_name, cf_name, block_size, chuncks);

    for (auto i : chuncks) {
        for (auto j : i) {
            std::cout << j.first << "->" << j.second << "\n";
        }
        std::cout << "\n";
    }

    int64_t total_file_size = 0;

    for (auto i : path) {
        boost::filesystem::path check_file(i);
        if (!boost::filesystem::is_regular(check_file)) {
            LOG(FATAL) << i << " IS NOT REGULAR DATA";
        }
        total_file_size += boost::filesystem::file_size(check_file);
    }

    create_table(table_name, chuncks.size());
    create_cf(table_name, cf_name, StorageType::type::InMemoryKeyValue);
    std::vector<std::string> row;
    std::vector<std::string> column;
    int64_t buffer_size = 100;
    char buffer[buffer_size];
    std::string single_value;
    std::vector<std::string> value;


    for (uint64_t shard_id = 0; shard_id < chuncks.size(); ++shard_id) {
        row.clear();
        column.clear();
        value.clear();
        for (auto i : chuncks[shard_id]) {
            memset(buffer, 0, buffer_size);
            single_value.clear();
            std::ifstream data(i.first);

            row.push_back(i.first);
            column.push_back(std::to_string(i.second));
            data.seekg(block_size * i.second);

            std::cout << data.eofbit << "\n";

            int64_t read_size = 0;

            while(!data.eof()) {
                if ((read_size + buffer_size) >= block_size) {
                    data.read(buffer, block_size - read_size);
                    single_value.append(std::string(buffer, data.gcount()));
                    read_size += data.gcount();
                    break;
                }
                data.read(buffer, buffer_size);
                single_value.append(std::string(buffer, data.gcount()));
                read_size += data.gcount();
            }
            value.push_back(single_value);
            data.close();
        }

        Storage::vector_put(table_name, cf_name, shard_id, row, column, value);
    }

    return 1;
}

int64_t find_local_file(std::vector<std::string>& files,
                        std::vector<int64_t>& sizes,
                        const std::string& path) {

    boost::filesystem::path dir_path(path);
    if (!boost::filesystem::exists( dir_path)){
        LOG(FATAL) << "CANNOT FIND PATH "
                   << path;
    }

    if (!boost::filesystem::is_directory(dir_path)) {
                LOG(FATAL) << path << " IS NOT DIR";
    }

    boost::filesystem::directory_iterator end_itr;

    for (boost::filesystem::directory_iterator itr(dir_path); itr != end_itr; ++itr) {

        if (boost::filesystem::is_directory(itr->status())) {
            find_local_file(files, sizes, itr->path().string());
        } else if (boost::filesystem::is_regular(itr->status())) {
            files.push_back(itr->path().string());
            sizes.push_back(boost::filesystem::file_size(itr->path()));
        }
    }
    return 1;
}

int64_t load_local_file_dir(const std::string& path,
                        const std::string& table_name,
                        const std::string& cf_name,
                        const int64_t block_size) {

    std::vector<std::string> txt_files;
    std::vector<int64_t> txt_sizes;
    find_local_file(txt_files, txt_sizes, path);

    load_local_file_regular(txt_files, txt_sizes, table_name, cf_name, block_size);

    return 1;
}

int64_t load_local_file(const std::string& path,
                    const std::string& table_name,
                    const std::string& cf_name) {
    load_local_file(path, table_name, cf_name, 1024*1024*64);
    return 1;
}

int64_t load_local_file(const std::string& path,
                    const std::string& table_name,
                    const std::string& cf_name,
                    const int64_t block_size) {
    boost::filesystem::path check_path(path);
    if(boost::filesystem::is_directory(check_path)) {
        load_local_file_dir(path, table_name, cf_name, block_size);
    } else if (boost::filesystem::is_regular(check_path)) {
        std::vector<std::string> _path;
        std::vector<int64_t> _size;
        _path.push_back(path);
        _size.push_back(boost::filesystem::file_size(check_path));
        load_local_file_regular(_path, _size, table_name, cf_name, block_size);
    } else {
        LOG(FATAL) << path << "IS NOT A DIR OR A REGULAR FILE";
    }

    return 1;
}

int64_t find_hdfs_file(std::vector<std::string>& files,
                    std::vector<int64_t>& sizes,
                    const std::string& path,
                    hdfsFS fs) {
    hdfsFileInfo *check_path;
    check_path = hdfsGetPathInfo(fs, path.c_str());

    if (check_path->mKind == tObjectKind::kObjectKindFile) {
        files.push_back(path);
        sizes.push_back(check_path->mSize);
    } else if (check_path->mKind == tObjectKind::kObjectKindDirectory) {
        hdfsFileInfo *check_dir;
        int numbers;
        check_dir = hdfsListDirectory(fs, path.c_str(), &numbers);
        for (int i = 0; i < numbers; ++i) {
            if (check_dir->mKind == tObjectKind::kObjectKindFile) {
                files.push_back(check_dir->mName);
                sizes.push_back(check_dir->mSize);
            } else if (check_dir->mKind == tObjectKind::kObjectKindDirectory) {
                find_hdfs_file(files, sizes, check_dir->mName, fs);
            }
            ++check_dir;
        }
    } else {
        LOG(FATAL) << "CANNOT DETECT HDFS FILE TYPE";
    }
    return 1;
}

int64_t load_hdfs_file_regular(const std::vector<std::string>& path,
                            const std::vector<int64_t>& size,
                            const std::string& table_name,
                            const std::string& cf_name,
                            const int64_t block_size,
                            hdfsFS fs) {
    std::vector<std::vector<std::pair<std::string, int64_t>>> full_chuncks;

    load_file_regular(path, size, table_name, cf_name, block_size, full_chuncks);
    std::cout << full_chuncks.size() << "###\n";
    for (auto i : full_chuncks) {
        for (auto j : i) {
            std::cout << j.first << "->" << j.second << "\n";
        }
        std::cout << "\n";
    }

    return 1;
}


int64_t load_hdfs_file_dir(const std::string& path,
                            const std::string& table_name,
                            const std::string& cf_name,
                            const int64_t block_size,
                            hdfsFS fs) {
    std::vector<std::string> files;
    std::vector<int64_t> sizes;
    find_hdfs_file(files, sizes, path, fs);
    load_hdfs_file_regular(files, sizes, table_name, cf_name, block_size, fs);
    return 1;
}

int64_t load_hdfs_file(const std::string& path,
                    const std::string& table_name,
                    const std::string& cf_name,
                    const int64_t block_size) {

    struct hdfsBuilder *builder = hdfsNewBuilder();
    hdfsBuilderSetNameNode(builder, NodeInfo::singleton()._hdfs_namenode.c_str());
    hdfsBuilderSetNameNodePort(builder, NodeInfo::singleton()._hdfs_namenode_port);
    hdfsFS fs = hdfsBuilderConnect(builder);

    if (hdfsExists(fs, path.c_str()) == -1) {
        LOG(FATAL) << "CANNOT FIND HDFS PATH " << path;
    }

    hdfsFileInfo *check_path;
    check_path = hdfsGetPathInfo(fs, path.c_str());

    if (check_path->mKind == tObjectKind::kObjectKindFile) {
        std::vector<std::string> regular_path;
        std::vector<int64_t> regular_size;
         regular_path.push_back(path);
         regular_size.push_back(check_path->mSize);
         load_hdfs_file_regular(regular_path, regular_size, table_name, cf_name, block_size, fs);
    } else if (check_path->mKind == tObjectKind::kObjectKindDirectory) {
        load_hdfs_file_dir(path, table_name, cf_name, block_size, fs);
    } else {
        LOG(FATAL) << "CANNOT DETECT HDFS FILE TYPE";
    }

    hdfsDisconnect(fs);

    return 1;
}

int64_t load_hdfs_file(const std::string& path,
                    const std::string& table_name,
                    const std::string& cf_name) {
    load_hdfs_file(path, table_name, cf_name, 1024*1024*64);
    return 1;
}

}
}


