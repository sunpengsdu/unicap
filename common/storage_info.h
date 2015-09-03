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

    std::map<std::string, Table> _table_info;
    std::map<std::string, std::vector<ColumnFamily>> _cf_info;

private:

};

}
}

#endif /* UNICAP_COMMON_STORAGE_INFO_H_ */
