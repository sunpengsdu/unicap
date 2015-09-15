/*
 * in_memory_key_value.cpp
 *
 *  Created on: 15 Sep 2015
 *      Author: sunshine
 */
#include "in_memory_key_value.h"
namespace ntu {
namespace cap {

InMemoryKeyValue::InMemoryKeyValue():KVStorage() {
}

InMemoryKeyValue::InMemoryKeyValue(const std::string table_name,
                                const int64_t shard_id,
                                const std::string cf_name):
                                KVStorage(table_name, shard_id, cf_name) {
}

InMemoryKeyValue::~InMemoryKeyValue() {
}

int64_t InMemoryKeyValue::vector_put(std::vector<std::string> row_key,
                   std::vector<std::string> column_key,
                   std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);
    for (int i = 0; i < row_key.size(); ++i) {
        _storage_container[row_key[i]][column_key[i]] = value[i];
    }
    return 1;
}

int64_t InMemoryKeyValue::timely_vector_put(std::vector<std::string> row_key,
                          std::vector<std::string> column_key,
                          int64_t time_stamp,
                          std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);
    LOG(FATAL) << "NOT IMPLEMENTED \n";
    return 1;
}

void InMemoryKeyValue::vector_get(std::vector<std::string> row_key,
                                std::vector<std::string> column_key,
                                std::vector<std::string>& value) {
    CHECK_EQ(row_key.size(), column_key.size());
    value.clear();

    read_lock _lock(KVStorage::_rwmutex);

    for (int i = 0; i < row_key.size(); ++i) {
        if (_storage_container.find(row_key[i]) == _storage_container.end()
                || _storage_container[row_key[i]].find(column_key[i])
                == _storage_container[row_key[i]].end() ) {
            value.push_back("NULL");
        } else {
            value.push_back(_storage_container[row_key[i]][column_key[i]]);
        }
    }
}

void InMemoryKeyValue::scan_all(std::vector<std::vector<std::string>>& value) {
    read_lock _lock(KVStorage::_rwmutex);
    value.clear();
    value.resize(3);
    for (auto& row_key : _storage_container) {
        for (auto& column_key : row_key.second) {
            value[0].push_back(row_key.first);
            value[1].push_back(column_key.first);
            value[2].push_back(column_key.second);
        }
    }
}

void InMemoryKeyValue::scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value) {
    read_lock _lock(KVStorage::_rwmutex);
    value.clear();
    LOG(FATAL) << "NOT IMPLEMENTED \n";
}


}
}



