/*
 * column_family.cpp
 *
 *  Created on: 15 Sep 2015
 *      Author: sunshine
 */
#include "column_family.h"

namespace ntu {
namespace cap {

ColumnFamily::ColumnFamily() {
}

ColumnFamily::ColumnFamily(const ColumnFamilyProperty& cf_property) {
    _cf_property = cf_property;
}

ColumnFamily::ColumnFamily(const std::string& cf_name,
                 const StorageType::type storage_type) {
    _cf_property.cf_name = cf_name;
    _cf_property.storage_type = storage_type;
}

int64_t ColumnFamily::set_storage_type(const StorageType::type storage_type) {
    _cf_property.storage_type = storage_type;
    return 1;
}

}
}


