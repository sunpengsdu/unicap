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

    std::string single_key;

    for (uint64_t i = 0; i < row_key.size(); ++i) {
        single_key.clear();
        single_key.append(row_key[i]);
        single_key.append("!");
        single_key.append(column_key[i]);
        _storage_container[single_key] = value[i];
    }
    return 1;
}

int64_t InMemoryKeyValue::vector_merge(std::vector<std::string> row_key,
                   std::vector<std::string> column_key,
                   std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);

    std::string single_key;
    std::string merged_value;
    std::vector<std::string> tokens;

    for (uint64_t i = 0; i < row_key.size(); ++i) {
        tokens.clear();
        merged_value.clear();
        boost::split(tokens, column_key[i], boost::algorithm::is_any_of("@"));

        single_key.clear();
        single_key.append(row_key[i]);
        single_key.append("!");
        single_key.append(tokens[0]);
        merged_value.append("\n");
        merged_value.append(value[i]);
        _storage_container[single_key].append(merged_value);
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

    std::string single_key;
    std::string single_value;

    read_lock _lock(KVStorage::_rwmutex);

    for (uint64_t i = 0; i < row_key.size(); ++i) {
        single_key.clear();
        single_value.clear();
        single_key.append(row_key[i]);
        single_key.append("!");
        single_key.append(column_key[i]);

        auto result = _storage_container.find(single_key);
        if ( result == _storage_container.end()) {
            value.push_back("NULL");
        } else {
            value.push_back(result->second);
        }
    }
}

void InMemoryKeyValue::scan_all(std::vector<std::vector<std::string>>& value) {
    read_lock _lock(KVStorage::_rwmutex);
    value.clear();
    value.resize(3);
    std::vector<std::string> tokens;
    std::string single_key;
    std::string single_value;

    for (auto& key : _storage_container) {
        tokens.clear();
        single_key = key.first;
        single_value = key.second;

        boost::split(tokens, single_key, boost::algorithm::is_any_of("!"));

        value[0].push_back(tokens[0]);
        value[1].push_back(tokens[1]);
        value[2].push_back(single_value);
    }
}

void InMemoryKeyValue::scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value) {
    read_lock _lock(KVStorage::_rwmutex);
    value.clear();
    LOG(FATAL) << "NOT IMPLEMENTED \n";

}

std::map<std::string, std::string>* InMemoryKeyValue::storage_ptr(){

    return &_storage_container;
}

}
}



