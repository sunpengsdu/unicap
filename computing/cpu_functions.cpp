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

#include "cpu_functions.h"

namespace ntu {
namespace cap {

CPUFunctions::CPUFunctions() {
    _cpu_functions_p["test"] = test;
    _cpu_functions_p["load_hdfs"] = load_hdfs;
    _cpu_functions_p["save_hdfs"] = save_hdfs;
}

int64_t CPUFunctions::test (TaskNode new_task) {
    std::cout << "test the function\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    return 1;
}

int64_t CPUFunctions::load_hdfs (TaskNode new_task) {

    struct hdfsBuilder *builder = hdfsNewBuilder();
    hdfsBuilderSetForceNewInstance(builder);
    hdfsBuilderSetNameNode(builder, NodeInfo::singleton()._hdfs_namenode.c_str());
    hdfsBuilderSetNameNodePort(builder, NodeInfo::singleton()._hdfs_namenode_port);
    hdfsFS fs = hdfsBuilderConnect(builder);

    std::vector<std::vector<std::string>> hdfs_property;

    StorageInfo::singleton()._cf_ptr[new_task.src_table_name]
                                 [new_task.src_shard_id]
                                 [new_task.src_cf_name] ->
                                 scan_all(hdfs_property);

    uint64_t entries_num = hdfs_property[0].size();
    int64_t buffer_size = 1024;
    char buffer[buffer_size];
    std::vector<std::string> row;
    std::vector<std::string> column;
    std::vector<std::string> value;
    std::string single_value;


    for (uint64_t i = 0; i < entries_num; ++i) {
        memset(buffer, 0, buffer_size);
        std::string path = hdfs_property[0][i];
        int shard_id = std::stoi (hdfs_property[1][i], nullptr, 10);
        int block_size = std::stoi (hdfs_property[2][i],nullptr, 10);

        row.push_back(path);
        column.push_back(hdfs_property[1][i]);
        single_value.clear();

        hdfsFile file = hdfsOpenFile(fs, path.c_str(), O_RDONLY, 0, 0, 0);
        hdfsSeek(fs, file, block_size * shard_id);

        if (shard_id != 0) {
            while (hdfsRead(fs, file, buffer, 1)) {
                if (buffer[0] == '\n') {
                    break;
                }
            }
        }

        int64_t total_read_size = 0;
        int64_t each_read_size = 0;
        bool    eof = false;
        while(!eof) {
            memset(buffer, 0, buffer_size);
            if ((total_read_size + buffer_size) >= block_size) {
                each_read_size = hdfsRead(fs, file, buffer, buffer_size);
                single_value.append(std::string(buffer, each_read_size));
                total_read_size += each_read_size;
                break;
            }
            each_read_size = hdfsRead(fs, file, buffer, buffer_size);
            if (each_read_size == 0) {
                eof = true;
                break;
            }
            single_value.append(std::string(buffer, each_read_size));
            total_read_size += each_read_size;
        }
        while (!eof) {
            memset(buffer, 0, buffer_size);
            each_read_size = hdfsRead(fs, file, buffer, buffer_size);
            if (each_read_size == 0) {
                 eof = true;
                 break;
             }
            std::string check_buffer(buffer, each_read_size);
            std::size_t found = check_buffer.find("\n");

            if (found == std::string::npos) {
                single_value.append(std::string(buffer, each_read_size));
            } else {
                single_value.append(std::string(buffer, found));
                break;
            }
        }
        value.push_back(single_value);
        hdfsCloseFile(fs, file);
    }
    StorageInfo::singleton()._cf_ptr[new_task.dst_table_name]
                                     [new_task.src_shard_id]
                                     [new_task.dst_cf_name] ->
                                     vector_put(row, column, value);
    hdfsDisconnect(fs);
    return 1;
}

int64_t CPUFunctions::save_hdfs (TaskNode new_task) {
    struct hdfsBuilder *builder = hdfsNewBuilder();
    hdfsBuilderSetForceNewInstance(builder);
    hdfsBuilderSetNameNode(builder, NodeInfo::singleton()._hdfs_namenode.c_str());
    hdfsBuilderSetNameNodePort(builder, NodeInfo::singleton()._hdfs_namenode_port);
    hdfsFS fs = hdfsBuilderConnect(builder);

    std::string target_dir;
    target_dir.append(NodeInfo::singleton()._root_dir);
    if (target_dir.back() != '/') {
        target_dir.append("/");
    }
    target_dir.append(NodeInfo::singleton()._app_name);
    target_dir.append("/");
    target_dir.append(new_task.src_table_name);
    target_dir.append("/");
    target_dir.append(new_task.src_cf_name);

    if (hdfsExists(fs, target_dir.c_str()) == -1) {
        hdfsCreateDirectory(fs, target_dir.c_str());
    }

    std::string target_path;
    target_path.append(target_dir);
    target_path.append("/");
    target_path.append(std::to_string(new_task.src_shard_id));

    if (hdfsExists(fs, target_dir.c_str()) == 0) {
        hdfsDelete(fs, target_path.c_str(), 0);
    }

    hdfsFile file = hdfsOpenFile(fs, target_path.c_str(), O_WRONLY, 0, 0, 0);

    std::vector<std::vector<std::string>> data_to_hdfs;

    StorageInfo::singleton()._cf_ptr[new_task.src_table_name]
                                 [new_task.src_shard_id]
                                 [new_task.src_cf_name] ->
                                 scan_all(data_to_hdfs);

    for (uint64_t i = 0; i < data_to_hdfs[0].size(); ++i) {
        hdfsWrite(fs, file, data_to_hdfs[0][i].c_str(), data_to_hdfs[0][i].size());
        hdfsWrite(fs, file, "\n", 1);
        hdfsWrite(fs, file, data_to_hdfs[1][i].c_str(), data_to_hdfs[1][i].size());
        hdfsWrite(fs, file, "\n", 1);
        hdfsWrite(fs, file, data_to_hdfs[2][i].c_str(), data_to_hdfs[2][i].size());
    }

    hdfsCloseFile(fs, file);
    hdfsDisconnect(fs);



    auto s_ptr = Storage::storage("s", "p_hdfs_property", new_task.src_shard_id);
    auto ppp = std::dynamic_pointer_cast<InMemoryKeyValue>(s_ptr)->storage_ptr();
    std::cout << ppp->begin()->first << "#####\n";

    return 1;
}

}
}


