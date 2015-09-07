/*
 * kv_base.h
 *
 *  Created on: 3 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_STORAGE_KV_BASE_H_
#define NTU_CAP_UNICAP_STORAGE_KV_BASE_H_

#include <map>
#include <vector>
#include <list>
#include <string>
#include <glog/logging.h>

namespace ntu {
namespace cap {

class KVStorage {
public:
    KVStorage() { }

    virtual ~KVStorage() {
    }

    virtual int64_t vector_put(std::vector<std::string> row_key,
                                std::vector<std::string> column_key,
                                std::vector<std::string> value) = 0;

    virtual int64_t timely_vector_put(std::vector<std::string> row_key,
                                std::vector<std::string> column_key,
                                int64_t time_stamp,
                                std::vector<std::string> value) = 0;

    virtual void vector_get(std::vector<std::string> row_key,
                            std::vector<std::string> column_key,
                            std::vector<std::string>& value) = 0;

    virtual void scan_all(std::vector<std::vector<std::string>>& value) = 0;

    virtual void scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value) = 0;

};

}
}
#endif /* UNICAP_STORAGE_KV_BASE_H_ */
