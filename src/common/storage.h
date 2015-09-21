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

#ifndef UNICAP_COMMON_STORAGE_H_
#define UNICAP_COMMON_STORAGE_H_

#include "table.h"
#include "node_info.h"
#include "storage_info.h"
#include "../gen/JobTracker.h"
#include "../gen/TaskTracker.h"

namespace ntu {
namespace cap {

class Storage {
public:
    static int64_t vector_put(const std::string table,
                            const std::string cf,
                            int64_t shard_id,
                            std::vector<std::string> row_key,
                            std::vector<std::string> column_key,
                            std::vector<std::string> value);

    static int64_t timely_vector_put(const std::string table,
                            const std::string cf,
                            int64_t shard_id,
                            std::vector<std::string> row_key,
                            std::vector<std::string> column_key,
                            int64_t time_stamp,
                            std::vector<std::string> value);

    static int64_t vector_get(const std::string table,
                            const std::string cf,
                            int64_t shard_id,
                            std::vector<std::string> row_key,
                            std::vector<std::string> column_key,
                            std::vector<std::string>& value);

    static void scan_all(const std::string table,
                        const std::string cf,
                        int64_t shard_id,
                        std::vector<std::vector<std::string>>& value);

    static void scan_by_time(const std::string table,
                        const std::string cf,
                        int64_t shard_id,
                        int64_t time_stamp,
                        std::vector<std::vector<std::string>>& value);

    static int64_t get_shard_num(const std::string table);

    static KeyPartition get_table_partition(const std::string table);

    static std::shared_ptr<KVStorage> storage(std::string table, std::string cf, int64_t shard_id);
};


}
}
#endif /* UNICAP_COMMON_STORAGE_H_ */
