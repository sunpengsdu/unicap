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

#ifndef NTU_CAP_UNICAP_STORAGE_HDFS_KEY_VALUE_H_
#define NTU_CAP_UNICAP_STORAGE_HDFS_KEY_VALUE_H_

#include <map>
#include "kv_base.h"
#include "../tools/include/hdfs/hdfs.h"

namespace ntu {
namespace cap {

class HdfsKeyValue : public KVStorage {

public:

    HdfsKeyValue();

    HdfsKeyValue(const std::string table_name,
                const int64_t shard_id,
                const std::string cf_name);

    ~HdfsKeyValue();

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

    struct hdfsBuilder* storage_ptr();

    hdfsFS _fs;
    struct hdfsBuilder *_builder;
    std::vector<std::vector<std::string>> _property;

    //std::map<int64_t, std::string> _history_data;
};

}
}




#endif /* NTU_CAP_UNICAP_STORAGE_HDFS_KEY_VALUE_H_ */
