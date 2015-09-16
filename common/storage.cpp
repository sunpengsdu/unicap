/*
 * storage.cpp
 *
 *  Created on: 15 Sep 2015
 *      Author: sunshine
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
    i->method()->vector_put(table,shard_id, cf, row_key, column_key, value);
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
    i->method()->timely_vector_put(table, shard_id, cf, row_key, column_key, time_stamp, value);
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
    i->method()->vector_get(value, table, shard_id, cf, row_key, column_key);
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

}
}


