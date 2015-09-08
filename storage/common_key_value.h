/*
 * common_key_value.h
 *
 *  Created on: 6 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_STORAGE_COMMON_KEY_VALUE_H_
#define NTU_CAP_UNICAP_STORAGE_COMMON_KEY_VALUE_H_

#include <unordered_map>
#include "./kv_base.h"

namespace ntu {
namespace cap {

class CommonKeyValue : public KVStorage {

public:

    CommonKeyValue() : KVStorage() {


    }
    ~CommonKeyValue() {

    }

    int64_t vector_put(std::vector<std::string> row_key,
                                std::vector<std::string> column_key,
                                std::vector<std::string> value) {
        write_lock _lock(KVStorage::_rwmutex);
        for (int i = 0; i < row_key.size(); ++i) {
            _storage_container[row_key[i]][column_key[i]] = value[i];
        }
        return 1;
    }

    int64_t timely_vector_put(std::vector<std::string> row_key,
                                std::vector<std::string> column_key,
                                int64_t time_stamp,
                                std::vector<std::string> value) {
        write_lock _lock(KVStorage::_rwmutex);
        LOG(FATAL) << "NOT IMPLEMENTED \n";
        return 1;
    }

    void vector_get(std::vector<std::string> row_key,
                            std::vector<std::string> column_key,
                            std::vector<std::string>& value) {
        read_lock _lock(KVStorage::_rwmutex);

        for (int i = 0; i < row_key.size(); ++i) {
            if (_storage_container.find(row_key[i]) == _storage_container.end()
                || _storage_container[row_key[i]].find(column_key[i])
                        == _storage_container[row_key[i]].end() ) {
                value.push_back(_storage_container[row_key[i]][column_key[i]]);
            } else {
                value.push_back("NULL");
            }
        }
    }

    void scan_all(std::vector<std::vector<std::string>>& value) {
        read_lock _lock(KVStorage::_rwmutex);

        value.resize(3);
        for (auto& row_key : _storage_container) {
            for (auto& column_key : row_key.second) {
                value[0].push_back(row_key.first);
                value[1].push_back(column_key.first);
                value[2].push_back(column_key.second);
            }
        }
    }

    void scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value) {
        read_lock _lock(KVStorage::_rwmutex);
        LOG(FATAL) << "NOT IMPLEMENTED \n";
    }

    std::unordered_map<std::string,
                    std::unordered_map<std::string,
                                    std::string> > _storage_container;
    //std::map<int64_t, std::string> _history_data;
};

}
}

#endif /* UNICAP_STORAGE_COMMON_KEY_VALUE_H_ */
