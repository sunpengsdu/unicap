/*
 * storage_info.cpp
 *
 *  Created on: 15 Sep 2015
 *      Author: sunshine
 */
#include "storage_info.h"
namespace ntu {
namespace cap {

StorageInfo::StorageInfo() {
}

StorageInfo& StorageInfo::singleton() {
   static StorageInfo storage_info;
   return storage_info;
}

}
}



