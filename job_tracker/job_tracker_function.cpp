/*
 * job_tracker_function.cpp
 *
 *  Created on: 4 Sep 2015
 *      Author: sunshine
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
                     const KeyPartition partition) {

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

    VLOG(2) << "CREATE TABLE " << table_name;
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

    VLOG(2) << "CREATE TABLE " << table_name;
    return 1;
}

int64_t create_cf(const std::string& table_name,
                  const std::string cf_name,
                  const StorageType::type cf_type) {

    ColumnFamily new_cf(cf_name, cf_type);

    for (auto& exist_cf : StorageInfo::singleton()._cf_info[table_name]) {
        if (exist_cf.first == cf_name) {
            LOG(FATAL) << "CF ALREADY EXISTS !";
        }
    }

    StorageInfo::singleton()._cf_info[table_name][cf_name] = new_cf;

    for (auto i : NodeInfo::singleton()._client_task_tracker) {
        i.second->open_transport();
        i.second->method()->create_cf(table_name, new_cf._cf_property);
        i.second->close_transport();
    }

    VLOG(2) << "CREATE CF " << cf_name << " FOR TABLE " << table_name;
    return 1;
}

int64_t load_local_file_regular(const std::vector<std::string> path,
                    const std::string table_name,
                    const std::string cf_name,
                    const int64_t block_size) {

    int64_t total_file_size = 0;

    for (auto i : path) {
        boost::filesystem::path check_file(i);
        if (!boost::filesystem::is_regular(check_file)) {
            LOG(FATAL) << i << " IS NOT REGULAR DATA";
        }
        total_file_size += boost::filesystem::file_size(check_file);
    }


    int64_t shard_num = total_file_size/block_size + 1;
    create_table(table_name, shard_num);
    create_cf(table_name, cf_name, StorageType::type::InMemoryKeyValue);

    std::string line;
    int64_t line_id = 1;
    int64_t c_size = 0;
    int64_t shard_id = 0;
    std::vector<std::string> row;
    std::vector<std::string> column;
    std::vector<std::string> value;

    for (auto i : path) {
        std::ifstream data(i);
        std::string row_key(i);
        row_key.append("#");

        while (std::getline(data, line)) {
            row.push_back(row_key.append(std::to_string(line_id)));
            column.push_back("");
            value.push_back(line);
            c_size = c_size + line.size();
            if (c_size >= block_size) {
                Storage::vector_put(table_name, cf_name, shard_id, row, column, value);
                c_size = 0;
                row.clear();
                column.clear();
                value.clear();
                if (shard_id < (shard_num - 1)) {
                    ++shard_id;
                }
            }
            line_id++;
        }
    }
    Storage::vector_put(table_name, cf_name, shard_id, row, column, value);
    return 1;
}

int64_t find_local_file(const std::string path, std::vector<std::string>& result) {

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
            find_local_file(itr->path().string(), result);
        } else if (boost::filesystem::is_regular(itr->status())) {
            result.push_back(itr->path().string());
           //std::cout << *itr << std::endl;
        }
    }

    return 1;
}

int64_t load_local_file_dir(const std::string path,
                        const std::string table_name,
                        const std::string cf_name,
                        const int64_t block_size) {

    std::vector<std::string> txt_files;
    find_local_file(path, txt_files);
    for(auto i : txt_files) {
        std::cout << i << "\n";
    }
    load_local_file_regular(txt_files, table_name, cf_name, block_size);

    return 1;
}

int64_t load_local_file(const std::string path,
                    const std::string table_name,
                    const std::string cf_name) {
    load_local_file(path, table_name, cf_name, 1024*1024*16);
    return 1;
}

int64_t load_local_file(const std::string path,
                    const std::string table_name,
                    const std::string cf_name,
                    const int64_t block_size) {
    boost::filesystem::path check_path(path);
    if(boost::filesystem::is_directory(check_path)) {
        load_local_file_dir(path, table_name, cf_name, block_size);
    } else if (boost::filesystem::is_regular(check_path)) {
        std::vector<std::string> _path;
        _path.push_back(path);
        load_local_file_regular(_path, table_name, cf_name, block_size);
    } else {
        LOG(FATAL) << path << "IS NOT A DIR OR A REGULAR FILE";
    }

    return 1;
}

int64_t find_hdfs_file(std::vector<std::string>& files,
                    std::vector<int64_t>& sizes,
                    const std::string path,
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

int64_t load_hdfs_file_regular(const std::vector<std::string> path,
                            const std::vector<int64_t> size,
                            const std::string table_name,
                            const std::string cf_name,
                            const int64_t block_size,
                            hdfsFS fs) {
    for (auto i : path) {
        std::cout << i << "\n";
    }
    return 1;
}


int64_t load_hdfs_file_dir(const std::string path,
                            const std::string table_name,
                            const std::string cf_name,
                            const int64_t block_size,
                            hdfsFS fs) {
    std::vector<std::string> files;
    std::vector<int64_t> sizes;
    find_hdfs_file(files, sizes, path, fs);
    load_hdfs_file_regular(files, sizes, table_name, cf_name, block_size, fs);
    return 1;
}

int64_t load_hdfs_file(const std::string path,
                    const std::string table_name,
                    const std::string cf_name,
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

int64_t load_hdfs_file(const std::string path,
                    const std::string table_name,
                    const std::string cf_name) {
    load_hdfs_file(path, table_name, cf_name, 1024*1024*16);
    return 1;
}

}
}


