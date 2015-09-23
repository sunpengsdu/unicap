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

#include "storage.h"
namespace ntu {
namespace cap {

int64_t Storage::vector_put(const std::string table,
                        const std::string cf,
                        int64_t shard_id,
                        std::vector<std::string> row_key,
                        std::vector<std::string> column_key,
                        std::vector<std::string> value) {
    int64_t node_id = StorageInfo::singleton().
                            _table_info[table].
                            _table_property.
                            shard_location[shard_id];
    auto i =  NodeInfo::singleton()._client_task_tracker[node_id];
    i->open_transport();
    i->method()->vector_put_string(table,shard_id, cf, row_key, column_key, value);
    i->close_transport();
    return 1;

}


int64_t Storage::timely_vector_put(const std::string table,
                        const std::string cf,
                        int64_t shard_id,
                        std::vector<std::string> row_key,
                        std::vector<std::string> column_key,
                        int64_t time_stamp,
                        std::vector<std::string> value) {
    int64_t node_id = StorageInfo::singleton().
                            _table_info[table].
                            _table_property.
                            shard_location[shard_id];
    auto i =  NodeInfo::singleton()._client_task_tracker[node_id];
    i->open_transport();
    i->method()->timely_vector_put_string(table, shard_id, cf, row_key, column_key, time_stamp, value);
    i->close_transport();
    return 1;
}

int64_t Storage::vector_get(const std::string table,
                        const std::string cf,
                        int64_t shard_id,
                        std::vector<std::string> row_key,
                        std::vector<std::string> column_key,
                        std::vector<std::string>& value) {
    value.clear();
    int64_t node_id = StorageInfo::singleton().
                            _table_info[table].
                            _table_property.
                            shard_location[shard_id];
    auto i =  NodeInfo::singleton()._client_task_tracker[node_id];
    i->open_transport();
    i->method()->vector_get_string(value, table, shard_id, cf, row_key, column_key);
    i->close_transport();
    return 1;
}

void Storage::scan_all(const std::string table,
                    const std::string cf,
                    int64_t shard_id,
                    std::vector<std::vector<std::string>>& value) {
    value.clear();
    int64_t node_id = StorageInfo::singleton().
                           _table_info[table].
                           _table_property.
                           shard_location[shard_id];
    auto i =  NodeInfo::singleton()._client_task_tracker[node_id];
    i->open_transport();
    i->method()->scan_all(value, table, shard_id, cf);
    i->close_transport();
}

void Storage::scan_by_time(const std::string table,
                    const std::string cf,
                    int64_t shard_id,
                    int64_t time_stamp,
                    std::vector<std::vector<std::string>>& value) {
    value.clear();
    int64_t node_id = StorageInfo::singleton().
                           _table_info[table].
                           _table_property.
                           shard_location[shard_id];
    auto i =  NodeInfo::singleton()._client_task_tracker[node_id];
    i->open_transport();
    i->method()->scan_by_time(value, table, shard_id, cf, time_stamp);
    i->close_transport();
}

int64_t Storage::get_shard_num(const std::string table) {
    return StorageInfo::singleton()._table_info[table]._table_property.shard_num;
}

KeyPartition Storage::get_table_partition(const std::string table) {
    return StorageInfo::singleton()._table_info[table]._table_property.key_partition;
}

std::shared_ptr<KVStorage> Storage::storage(std::string table, std::string cf, int64_t shard_id) {
    return StorageInfo::singleton()._cf_ptr[table][shard_id][cf];
}


}
}


