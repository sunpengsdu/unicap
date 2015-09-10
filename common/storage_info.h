/*
 * storage_info.h
 *
 *  Created on: 3 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_COMMON_STORAGE_INFO_H_
#define NTU_CAP_UNICAP_COMMON_STORAGE_INFO_H_

#include <map>
#include <string>
#include "./table.h"
#include "./column_family.h"
#include "../gen/JobTracker.h"
#include "../gen/TaskTracker.h"
#include "../storage/storage_systems.h"

namespace ntu {
namespace cap {

class StorageInfo {
public:

    StorageInfo() {
    }

    static StorageInfo& singleton() {
        static StorageInfo storage_info;
        return storage_info;
    }

    std::unordered_map<std::string, Table> _table_info;
    std::unordered_map<std::string, std::map<std::string, ColumnFamily>> _cf_info;

    //table_name -> shard_id -> cf_name -> ptr
    std::unordered_map<std::string,
            std::unordered_map<int64_t,
            std::unordered_map<std::string,
            std::shared_ptr<KVStorage>>>> _cf_ptr;
private:

};

}
}

#endif /* UNICAP_COMMON_STORAGE_INFO_H_ */
