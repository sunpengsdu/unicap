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

#include "hdfs_key_value.h"

namespace ntu {
namespace cap {

   HdfsKeyValue::HdfsKeyValue():KVStorage() {
   }

   HdfsKeyValue::HdfsKeyValue(const std::string table_name,
                           const int64_t shard_id,
                           const std::string cf_name):
                           KVStorage(table_name, shard_id, cf_name) {

        _builder = hdfsNewBuilder();
        hdfsBuilderSetForceNewInstance(_builder);
        hdfsBuilderSetNameNode(_builder, NodeInfo::singleton()._hdfs_namenode.c_str());
        hdfsBuilderSetNameNodePort(_builder, NodeInfo::singleton()._hdfs_namenode_port);

        std::string cf_property;
        cf_property.append(cf_name);
        cf_property.append("_hdfs_property");

        auto i =  NodeInfo::singleton()._client_task_tracker[NodeInfo::singleton()._node_id];
        i->open_transport();
        i->method()->scan_all(_property, table_name, shard_id, cf_property);
        i->close_transport();
   }

   HdfsKeyValue::~HdfsKeyValue() {
   }

   int64_t HdfsKeyValue::vector_put(std::vector<std::string> row_key,
                      std::vector<std::string> column_key,
                      std::vector<std::string> value) {
       CHECK_EQ(row_key.size(), column_key.size());
       CHECK_EQ(row_key.size(), value.size());
       write_lock _lock(KVStorage::_rwmutex);
       LOG(FATAL) << "NOT IMPLEMENTED \n";
       return 1;
   }

   int64_t HdfsKeyValue::timely_vector_put(std::vector<std::string> row_key,
                             std::vector<std::string> column_key,
                             int64_t time_stamp,
                             std::vector<std::string> value) {
       CHECK_EQ(row_key.size(), column_key.size());
       CHECK_EQ(row_key.size(), value.size());
       write_lock _lock(KVStorage::_rwmutex);
       LOG(FATAL) << "NOT IMPLEMENTED \n";
       return 1;
   }

   void HdfsKeyValue::vector_get(std::vector<std::string> row_key,
                                   std::vector<std::string> column_key,
                                   std::vector<std::string>& value) {
       CHECK_EQ(row_key.size(), column_key.size());
       value.clear();

       read_lock _lock(KVStorage::_rwmutex);
       LOG(FATAL) << "NOT IMPLEMENTED \n";
   }

   void HdfsKeyValue::scan_all(std::vector<std::vector<std::string>>& value) {
        read_lock _lock(KVStorage::_rwmutex);
        value.clear();
        value.resize(3);
        uint64_t num_entries = _property[0].size();
        _fs = hdfsBuilderConnect(_builder);

        std::string single_value;

        for (uint64_t i = 0; i < num_entries; ++i) {
            int64_t buffer_size = 1024;
            char buffer[buffer_size];

            value[0].push_back(_property[0][i]);
            value[1].push_back(_property[1][i]);
            single_value.clear();

            hdfsFile file = hdfsOpenFile(_fs, _property[0][i].c_str(), O_RDONLY, 0, 0, 0);
            int shard_id = std::stoi (_property[1][i], nullptr, 10);
            int block_size = std::stoi (_property[2][i],nullptr, 10);

            hdfsSeek(_fs, file, block_size * shard_id);

            if (shard_id != 0) {
                while (hdfsRead(_fs, file, buffer, 1)) {
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
                    each_read_size = hdfsRead(_fs, file, buffer, buffer_size);
                    single_value.append(std::string(buffer, each_read_size));
                    total_read_size += each_read_size;
                    break;
                }
                each_read_size = hdfsRead(_fs, file, buffer, buffer_size);
                if (each_read_size == 0) {
                    eof = true;
                    break;
                }
                single_value.append(std::string(buffer, each_read_size));
                total_read_size += each_read_size;
              }
              while (!eof) {
                  memset(buffer, 0, buffer_size);
                  each_read_size = hdfsRead(_fs, file, buffer, buffer_size);
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
            value[2].push_back(single_value);
            hdfsCloseFile(_fs, file);
       }
       hdfsDisconnect(_fs);
   }

   void HdfsKeyValue::scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value) {
       read_lock _lock(KVStorage::_rwmutex);
       value.clear();
       LOG(FATAL) << "NOT IMPLEMENTED \n";
   }

   struct hdfsBuilder* HdfsKeyValue::storage_ptr() {
       return _builder;
   }

}
}
