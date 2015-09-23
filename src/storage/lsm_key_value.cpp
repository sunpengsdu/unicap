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
#include "lsm_key_value.h"

namespace ntu {
namespace cap {

LSMKeyValue::LSMKeyValue():KVStorage() {
}

LSMKeyValue::LSMKeyValue(const std::string table_name,
                        const int64_t shard_id,
                        const std::string cf_name)
            :KVStorage(table_name, shard_id, cf_name) {

    _path = "./lsm_key_value/";
    _path.append(table_name);
    _path.append("/");
    _path.append(std::to_string(shard_id));
    _path.append(cf_name);
    boost::filesystem::create_directories(_path);
    _options.create_if_missing = true;

    //  boost::filesystem::remove_all(_path);

    leveldb::Status status = leveldb::DB::Open(_options, _path, &_db);
    CHECK_EQ(status.ok(), true);
}

LSMKeyValue::~LSMKeyValue() {
}

int64_t LSMKeyValue::vector_put(std::vector<std::string> row_key,
                               std::vector<std::string> column_key,
                               std::vector<std::string> value) {

    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());

    std::string single_key;
    for (uint64_t i = 0; i < row_key.size(); ++i) {
        single_key.clear();
        single_key.append(row_key[i]);
        single_key.append("!");
        single_key.append(column_key[i]);
        _db->Put(leveldb::WriteOptions(), single_key, value[i]);
    }
    return 1;
}

int64_t LSMKeyValue::vector_merge(std::vector<std::string> row_key,
                               std::vector<std::string> column_key,
                               std::vector<std::string> value) {

    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());

    std::string single_key;
    for (uint64_t i = 0; i < row_key.size(); ++i) {
        single_key.clear();
        single_key.append(row_key[i]);
        single_key.append("!");
        single_key.append(column_key[i]);
        _db->Put(leveldb::WriteOptions(), single_key, value[i]);
    }
    return 1;
}

int64_t LSMKeyValue::timely_vector_put(std::vector<std::string> row_key,
                                    std::vector<std::string> column_key,
                                    int64_t time_stamp,
                                    std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());

    LOG(FATAL) << "NOT IMPLEMENTED \n";
    return 1;
}

void LSMKeyValue::vector_get(std::vector<std::string> row_key,
                            std::vector<std::string> column_key,
                            std::vector<std::string>& value) {
    CHECK_EQ(row_key.size(), column_key.size());
    value.clear();

    std::string single_key;
    std::string single_value;
    leveldb::Status s;

    for (uint64_t i = 0; i < row_key.size(); ++i) {
        single_key.clear();
        single_value.clear();

        single_key.append(row_key[i]);
        single_key.append("!");
        single_key.append(column_key[i]);

        s = _db->Get(leveldb::ReadOptions(), single_key, &single_value);
        if (s.ok()) {
            value.push_back(single_value);
        } else {
            value.push_back("NULL");
        }
    }
}

void LSMKeyValue::scan_all(std::vector<std::vector<std::string>>& value) {
    value.clear();
    value.resize(3);

    std::vector<std::string> tokens;
    std::string single_key;
    std::string single_value;

    value[0].reserve(1000);
    value[1].reserve(1000);
    value[2].reserve(1000);

    leveldb::Iterator* it = _db->NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next()) {
        tokens.clear();
        single_key = it->key().ToString();
        single_value = it->value().ToString();

        boost::split(tokens, single_key, boost::algorithm::is_any_of("!"));

        value[0].push_back(tokens[0]);
        value[1].push_back(tokens[1]);
        value[2].push_back(single_value);
    }
    delete it;
}

void LSMKeyValue::scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value) {
    LOG(FATAL) << "NOT IMPLEMENTED \n";
}

leveldb::DB* LSMKeyValue::storage_ptr(){
    return _db;
}

}
}



