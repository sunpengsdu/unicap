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

#ifndef NTU_CAP_UNICAP_STORAGE_IMAGE_KEY_VALUE_
#define NTU_CAP_UNICAP_STORAGE_IMAGE_KEY_VALUE_

#include <unordered_map>
#include <map>
#include "../tools/include/opencv2/opencv.hpp"
#include "./kv_base.h"

namespace ntu {
namespace cap {

class InMemoryImage : public KVStorage {

public:

    InMemoryImage();

    InMemoryImage(const std::string table_name,
                    const int64_t shard_id,
                    const std::string cf_name);

    ~InMemoryImage();

    int64_t vector_put(std::vector<std::string> row_key,
                       std::vector<std::string> column_key,
                       std::vector<std::string> value);

    int64_t vector_merge(std::vector<std::string> row_key,
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

    std::map<std::string, cv::Mat>* storage_ptr();

    std::map<std::string, cv::Mat> _storage_container;

};

}
}

#endif /* NTU_CAP_UNICAP_STORAGE_IMAGE_KEY_VALUE_ */
