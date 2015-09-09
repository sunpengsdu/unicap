/*
 * column_family.h
 *
 *  Created on: 3 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_COMMON_COLUMN_FAMILY_H_
#define NTU_CAP_UNICAP_COMMON_COLUMN_FAMILY_H_

#include <stdint.h>
#include <map>
#include <string>
#include "../gen/JobTracker.h"
#include "../gen/TaskTracker.h"
#include "./node_info.h"
#include "./table.h"

namespace ntu {
namespace cap {

class ColumnFamily {
public:
    ColumnFamily() {
    }

    ColumnFamily(const ColumnFamilyProperty& cf_property) {
        _cf_property = cf_property;
    }

    ColumnFamily(const std::string& cf_name,
                 const StorageType::type storage_type) {
        _cf_property.cf_name = cf_name;
        _cf_property.storage_type = storage_type;
    }

    int64_t set_storage_type(const StorageType::type storage_type) {
        _cf_property.storage_type = storage_type;
        return 1;
    }
    ColumnFamilyProperty _cf_property;
};

}
}
#endif /* UNICAP_COMMON_COLUMN_FAMILY_H_ */
