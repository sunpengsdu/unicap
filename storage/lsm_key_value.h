/*
 * lsm_key_value.h
 *
 *  Created on: 8 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_STORAGE_LSM_KEY_VALUE_H_
#define NTU_CAP_UNICAP_STORAGE_LSM_KEY_VALUE_H_

#include "./kv_base.h"
#include "../tools/include/leveldb/db.h"

namespace ntu {
namespace cap {

class LSMKeyValue: public KVStorage {

public:

    LSMKeyValue() : KVStorage() {
    }

    LSMKeyValue(const std::string table_name, const int64_t shard_id, const std::string cf_name)
        : KVStorage(table_name, shard_id, cf_name) {

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

    ~LSMKeyValue() {
    }

    int64_t vector_put(std::vector<std::string> row_key,
                                std::vector<std::string> column_key,
                                std::vector<std::string> value) {

        CHECK_EQ(row_key.size(), column_key.size());
        CHECK_EQ(row_key.size(), value.size());

        std::string single_key;
        for (int i = 0; i < row_key.size(); ++i) {
            single_key.clear();
            single_key.append(row_key[i]);
            single_key.append("!");
            single_key.append(column_key[i]);
            _db->Put(leveldb::WriteOptions(), single_key, value[i]);
        }
        return 1;
    }

    int64_t timely_vector_put(std::vector<std::string> row_key,
                                std::vector<std::string> column_key,
                                int64_t time_stamp,
                                std::vector<std::string> value) {
        CHECK_EQ(row_key.size(), column_key.size());
        CHECK_EQ(row_key.size(), value.size());

        LOG(FATAL) << "NOT IMPLEMENTED \n";
        return 1;
    }

    void vector_get(std::vector<std::string> row_key,
                            std::vector<std::string> column_key,
                            std::vector<std::string>& value) {
        CHECK_EQ(row_key.size(), column_key.size());
        value.clear();

        std::string single_key;
        std::string single_value;
        leveldb::Status s;

        for (int i = 0; i < row_key.size(); ++i) {
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

    void scan_all(std::vector<std::vector<std::string>>& value) {
        value.clear();
        value.resize(3);

        std::vector<std::string> tokens;
        std::string single_key;
        std::string single_value;

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

    void scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value) {
        LOG(FATAL) << "NOT IMPLEMENTED \n";
    }

    std::string _path;
    leveldb::DB* _db;
    leveldb::Options _options;
};

}
}

#endif /* UNICAP_STORAGE_LSM_KEY_VALUE_H_ */
