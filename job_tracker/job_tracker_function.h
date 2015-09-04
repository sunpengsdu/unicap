/*
 * job_tracker_function.h
 *
 *  Created on: 4 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_JOB_TRACKER_JOB_TRACKER_FUNCTION_H_
#define NTU_CAP_UNICAP_JOB_TRACKER_JOB_TRACKER_FUNCTION_H_

#include <iostream>
#include <chrono>
#include <thread>
#include <glog/logging.h>
#include "./job_tracker_server.h"
#include "../common/table.h"
#include "../common/column_family.h"
#include "../common/storage_info.h"

namespace ntu {
namespace cap {

std::thread start_job_tracker(int64_t thread_num = 10);

int64_t create_table(const std::string& table_name,
                    const int64_t shard_num);

int64_t create_table(const std::string& table_name,
                    const int64_t shard_num,
                    const KeyPartition partition);

int64_t create_table(const std::string& table_name,
                    const Table& base_table) ;

int64_t create_cf(const std::string& table_name,
                const std::string cf_name,
                const StorageType::type cf_type);

}
}

#endif /* UNICAP_JOB_TRACKER_JOB_TRACKER_FUNCTION_H_ */
