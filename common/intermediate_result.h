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

#ifndef UNICAP_COMMON_INTERMEDIATE_RESULT_H_
#define UNICAP_COMMON_INTERMEDIATE_RESULT_H_

#include "storage.h"

namespace std {
    static string to_string(string _val) {
        return _val;
    }
}

namespace ntu {
namespace cap {

template <class T_KEY, class T_COLUMN, class T_VALUE>
class IntermediateResult {
public:

    IntermediateResult(std::string table_name) {

        if (StorageInfo::singleton()._table_info.find(table_name)
                == StorageInfo::singleton()._table_info.end()) {
            LOG(FATAL) << "CANNOT FIND TABLE " << table_name;
        }

        int64_t shard_num = Storage::get_shard_num(table_name);
        KeyPartition partition = Storage::get_table_partition(table_name);
    }

    int64_t push_back(T_KEY row_key,
                    T_COLUMN column_key,
                    T_VALUE value) {
        _intermediate_result_container[row_key][column_key].push_back(value);
        return 1;
    }

    void set_zero(int* value) {
        *value = 0;
    }

    void set_zero(long* value) {
        *value = 0;
    }

    void set_zero(long long* value) {
        *value = 0;
    }

    void set_zero(unsigned* value) {
        *value = 0;
    }

    void set_zero(unsigned long* value) {
        *value = 0;
    }

    void set_zero(unsigned long long* value) {
        *value = 0;
    }

    void set_zero(float* value) {
        *value = 0;
    }

    void set_zero(double* value) {
        *value = 0;
    }

    void set_zero(long double* value) {
        *value = 0;
    }

    void set_zero(std::string* value) {
        value->clear();
    }

    int64_t merge_data() {
        T_VALUE merged_value;

        for (auto& row_data : _intermediate_result_container) {
            for (auto& column_data : row_data.second) {

                set_zero(&merged_value);

                for (auto& inter_result : column_data.second) {
                    merged_value += inter_result;
                }

                _merged_result_container[std::to_string(row_data.first)]
                                     [std::to_string(column_data.first)]
                                     = std::to_string(merged_value);
                column_data.second.clear();
            }
        }
        return 1;
    }

    std::unordered_map<T_KEY, std::unordered_map<T_COLUMN, std::vector<T_VALUE>>> _intermediate_result_container;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> _merged_result_container;
};

}
}


#endif /* UNICAP_COMMON_INTERMEDIATE_RESULT_H_ */
