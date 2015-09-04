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

class KVStorage {
public:
    KVStorage() { }

    virtual ~KVStorage() = 0;

    virtual get() = 0;

get_by_key() = 0;
};

#endif /* UNICAP_STORAGE_KV_BASE_H_ */
