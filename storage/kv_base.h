/*
 * kv_base.h
 *
 *  Created on: 3 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_STORAGE_KV_BASE_H_
#define NTU_CAP_UNICAP_STORAGE_KV_BASE_H_

#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <mutex>
#include <atomic>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/shared_lock_guard.hpp>
#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>


#include <glog/logging.h>

typedef boost::shared_mutex rwmutex;
typedef boost::shared_lock<rwmutex> read_lock;
typedef boost::unique_lock<rwmutex> write_lock;

namespace ntu {
namespace cap {

class KVStorage {
public:
    KVStorage() {
    }

    KVStorage(const std::string table_name, const int64_t shard_id, const std::string cf_name) {
        _table_name = table_name;
        _cf_name = cf_name;
        _shard_id = shard_id;
    }

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

    // std::mutex _lock;
    rwmutex _rwmutex;
    std::string _table_name;
    int64_t _shard_id;
    std::string _cf_name;
};

}
}
#endif /* UNICAP_STORAGE_KV_BASE_H_ */
