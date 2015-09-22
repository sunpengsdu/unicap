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

#include "dense_matrix.h"

namespace ntu {
namespace cap {

DenseMatrix::DenseMatrix():KVStorage() {
}

DenseMatrix::DenseMatrix(const std::string table_name,
                        const int64_t shard_id,
                        const std::string cf_name,
                        std::pair<int64_t, int64_t> size):
                        KVStorage(table_name, shard_id, cf_name) {
    _storage_container.resize(size.first, size.second);
    _storage_container.setRandom();
    //_storage_container.setZero();
}

DenseMatrix::~DenseMatrix() {
}

int64_t DenseMatrix::vector_put(std::vector<std::string> row_key,
                   std::vector<std::string> column_key,
                   std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);
    int64_t row = 0;
    int64_t column = 0;
    double matrix_value = 0.0;

    for (uint64_t i = 0; i < row_key.size(); ++i) {
        row = std::stol(row_key[i]);
        column = std::stol(column_key[i]);
        matrix_value = std::stod(value[i]);
        _storage_container(row, column) = matrix_value;
    }
    return 1;
}

int64_t DenseMatrix::timely_vector_put(std::vector<std::string> row_key,
                          std::vector<std::string> column_key,
                          int64_t time_stamp,
                          std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);
    LOG(FATAL) << "NOT IMPLEMENTED \n";
    return 1;
}

void DenseMatrix::vector_get(std::vector<std::string> row_key,
                                std::vector<std::string> column_key,
                                std::vector<std::string>& value) {
    CHECK_EQ(row_key.size(), column_key.size());
    value.clear();

    int64_t row = 0;
    int64_t column = 0;
    double result;
    read_lock _lock(KVStorage::_rwmutex);

    for (uint64_t i = 0; i < row_key.size(); ++i) {
        row = std::stol(row_key[i]);
        column = std::stol(column_key[i]);

        if (row >= _storage_container.rows() ||
                column >= _storage_container.cols()) {
            LOG(ERROR) << "DENSE MATRIX INDEX ERROR";
        }
        result = _storage_container(row, column);
        value.push_back(std::to_string(result));
    }
}

void DenseMatrix::scan_all(std::vector<std::vector<std::string>>& value) {
    read_lock _lock(KVStorage::_rwmutex);
    value.clear();
    value.resize(1);

    int64_t row = _storage_container.rows();
    int64_t column = _storage_container.cols();
    double result;

    for (int64_t i = 0; i < row; ++i) {
        for (int64_t j = 0; j < column; ++j) {
            result = _storage_container(i, j);
            value[0].push_back(std::to_string(result));
        }
    }
}

void DenseMatrix::scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value) {
    read_lock _lock(KVStorage::_rwmutex);
    value.clear();
    LOG(FATAL) << "NOT IMPLEMENTED \n";

}

Eigen::MatrixXd* DenseMatrix::storage_ptr(){

    return &_storage_container;
}


}
}
