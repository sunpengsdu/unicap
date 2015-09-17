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

#ifndef NTU_CAP_UNICAP_TASK_TRACKER_TASK_TRACKER_HANDLER_H
#define NTU_CAP_UNICAP_TASK_TRACKER_TASK_TRACKER_HANDLER_H

#include "../gen/TaskTracker.h"
#include "../common/node_info.h"
#include "../common/table.h"
#include "../common/column_family.h"
#include "../common/storage_info.h"
#include "../storage/storage_systems.h"

namespace ntu {
namespace cap {

class TaskTrackerHandler : virtual public TaskTrackerIf {
public:
    TaskTrackerHandler();

    void ping(std::string& _return);

    int64_t check_table(const std::string& table_name,
                        const int64_t shard_id,
                        const std::string& cf_name);

    int64_t create_table(const TableProperty& table_property);

    int64_t create_cf(const std::string& table_name, const ColumnFamilyProperty& cf_property);

    int64_t vector_put(const std::string& table_name,
                       const int64_t shard_id,
                       const std::string& cf_name,
                       const std::vector<std::string> & row_key,
                       const std::vector<std::string> & column_key,
                       const std::vector<std::string> & value);

    int64_t timely_vector_put(const std::string& table_name,
                              const int64_t shard_id,
                              const std::string& cf_name,
                              const std::vector<std::string> & row_key,
                              const std::vector<std::string> & column_key,
                              const int64_t time_stampe,
                              const std::vector<std::string> & value);

    void vector_get(std::vector<std::string> & _return,
                    const std::string& table_name,
                    const int64_t shard_id,
                    const std::string& cf_name,
                    const std::vector<std::string> & row_key,
                    const std::vector<std::string> & column_key);

    void scan_by_time(std::vector<std::vector<std::string> > & _return,
                      const std::string& table_name,
                      const int64_t shard_id,
                      const std::string& cf_name,
                      const int64_t time_stamp);

    void scan_all(std::vector<std::vector<std::string> > & _return,
                  const std::string& table_name,
                  const int64_t shard_id,
                  const std::string& cf_name);
private:
};

} //end namespace ntu
} //end namespace cap
#endif

//std::map<int64_t, TaskTrackerInfo> & _return
//boost::shared_ptr<UnicapClient<JobTrackerClient>> _client;
