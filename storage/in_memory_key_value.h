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

#ifndef NTU_CAP_UNICAP_STORAGE_COMMON_KEY_VALUE_H_
#define NTU_CAP_UNICAP_STORAGE_COMMON_KEY_VALUE_H_

#include <unordered_map>
#include "./kv_base.h"

namespace ntu {
namespace cap {

class InMemoryKeyValue : public KVStorage {

public:

    InMemoryKeyValue();

    InMemoryKeyValue(const std::string table_name,
                    const int64_t shard_id,
                    const std::string cf_name);

    ~InMemoryKeyValue();

    int64_t vector_put(std::vector<std::string> row_key,
                       std::vector<std::string> column_key,
                       std::vector<std::string> value);

    int64_t timely_vector_put(std::vector<std::string> row_key,
                              std::vector<std::string> column_key,
                              int64_t time_stamp,
                              std::vector<std::string> value);

    void vector_get(std::vector<std::string> row_key,
                    std::vector<std::string> column_key,
                    std::vector<std::string>& value);

    void scan_all(std::vector<std::vector<std::string>>& value);

    void scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value);

    std::unordered_map<std::string,
                    std::unordered_map<std::string,
                    std::string> > _storage_container;
    //std::map<int64_t, std::string> _history_data;
};

}
}

#endif /* UNICAP_STORAGE_COMMON_KEY_VALUE_H_ */
