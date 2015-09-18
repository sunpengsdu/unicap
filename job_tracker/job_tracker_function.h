/*
 *Copyright 2015 NTU (http://www.ntu.edu.sg/)
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
*/
#ifndef NTU_CAP_UNICAP_JOB_TRACKER_JOB_TRACKER_FUNCTION_H_
#define NTU_CAP_UNICAP_JOB_TRACKER_JOB_TRACKER_FUNCTION_H_
#include <math.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <string>
#include <fstream>
#include <glog/logging.h>
#include <boost/filesystem.hpp>

#include "job_tracker_server.h"
#include "../common/storage.h"
#include "../common/table.h"
#include "../common/column_family.h"
#include "../common/storage_info.h"
#include "../tools/include/hdfs/hdfs.h"

namespace ntu {
namespace cap {

std::thread start_job_tracker(int64_t thread_num = 10);

int64_t create_table(const std::string& table_name,
                     const int64_t shard_num);

int64_t create_table(const std::string& table_name,
                     const int64_t shard_num,
                     const KeyPartition& partition);

int64_t create_table(const std::string& table_name,
                     const Table& base_table) ;

int64_t create_cf(const std::string& table_name,
                  const std::string& cf_name,
                  const StorageType::type cf_type);

int64_t load_local_file(const std::string& path,
                    const std::string& table_name,
                    const std::string& cf_name);

int64_t load_local_file(const std::string& path,
                    const std::string& table_name,
                    const std::string& cf_name,
                    const int64_t block_size);

int64_t load_hdfs_file(const std::string& path,
                    const std::string& table_name,
                    const std::string& cf_name);

int64_t load_hdfs_file(const std::string& path,
                    const std::string& table_name,
                    const std::string& cf_name,
                    const int64_t block_size);
}
}

#endif /* UNICAP_JOB_TRACKER_JOB_TRACKER_FUNCTION_H_ */
