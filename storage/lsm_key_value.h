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

    LSMKeyValue();

    LSMKeyValue(const std::string table_name,
                const int64_t shard_id,
                const std::string cf_name);

    ~LSMKeyValue();

    int64_t vector_put(std::vector<std::string> row_key,
                       std::vector<std::string> column_key,
                       std::vector<std::string> value);

    int64_t timely_vector_put(std::vector<std::string> row_key,
                              std::vector<std::string> column_key,
                              int64_t time_stamp,
                              std::vector<std::string> value);

    void vector_get(std::vector<std::string> row_key,
                    std::vector<std::string> column_key,
                    std::vector<std::string>& value);

    void scan_all(std::vector<std::vector<std::string>>& value);

    void scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value);
    std::string _path;
    leveldb::DB* _db;
    leveldb::Options _options;
};

}
}

#endif /* UNICAP_STORAGE_LSM_KEY_VALUE_H_ */
