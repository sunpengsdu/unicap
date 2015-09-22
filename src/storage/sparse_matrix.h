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


#ifndef UNICAP_SRC_STORAGE_SPARSE_MATRIX_H_
#define UNICAP_SRC_STORAGE_SPARSE_MATRIX_H_

#include <unordered_map>
#include <map>
#include "./kv_base.h"
#include "../tools/include/Eigen/Sparse"

namespace ntu {
namespace cap {

class SparseMatrix : public KVStorage {

public:

    SparseMatrix();

    SparseMatrix(const std::string table_name,
                    const int64_t shard_id,
                    const std::string cf_name,
                    std::pair<int64_t, int64_t> size);

    ~SparseMatrix();

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

    Eigen::SparseMatrix<double>* storage_ptr();

    Eigen::SparseMatrix<double> _storage_container;
};

}
}


#endif /* UNICAP_SRC_STORAGE_SPARSE_MATRIX_H_ */
