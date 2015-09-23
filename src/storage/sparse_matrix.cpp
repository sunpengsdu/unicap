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

#include "sparse_matrix.h"

namespace ntu {
namespace cap {

SparseMatrix::SparseMatrix():KVStorage() {
}

SparseMatrix::SparseMatrix(const std::string table_name,
                        const int64_t shard_id,
                        const std::string cf_name,
                        std::pair<int64_t, int64_t> size):
                        KVStorage(table_name, shard_id, cf_name) {
    _storage_container.resize(size.first, size.second);
}

SparseMatrix::~SparseMatrix() {
}

int64_t SparseMatrix::vector_put(std::vector<std::string> row_key,
                   std::vector<std::string> column_key,
                   std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);
    int64_t row = 0;
    int64_t column = 0;
    double matrix_value = 0.0;

    typedef Eigen::Triplet<double> T;
	std::vector<T> tripletList;
	tripletList.reserve(row_key.size());

    for (uint64_t i = 0; i < row_key.size(); ++i) {
        row = std::stol(row_key[i]);
        column = std::stol(column_key[i]);
        matrix_value = std::stod(value[i]);
        tripletList.push_back(T(row, column, matrix_value));
    }

    _storage_container.setFromTriplets(tripletList.begin(), tripletList.end());
    return 1;
}

int64_t SparseMatrix::vector_merge(std::vector<std::string> row_key,
                   std::vector<std::string> column_key,
                   std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);
    int64_t row = 0;
    int64_t column = 0;
    double matrix_value = 0.0;

    typedef Eigen::Triplet<double> T;
    std::vector<T> tripletList;
    tripletList.reserve(row_key.size());

    for (uint64_t i = 0; i < row_key.size(); ++i) {
        row = std::stol(row_key[i]);
        column = std::stol(column_key[i]);
        matrix_value = std::stod(value[i]);
        tripletList.push_back(T(row, column, matrix_value));
    }

    _storage_container.setFromTriplets(tripletList.begin(), tripletList.end());
    return 1;
}

int64_t SparseMatrix::timely_vector_put(std::vector<std::string> row_key,
                          std::vector<std::string> column_key,
                          int64_t time_stamp,
                          std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);
    LOG(FATAL) << "NOT IMPLEMENTED \n";
    return 1;
}

void SparseMatrix::vector_get(std::vector<std::string> row_key,
                                std::vector<std::string> column_key,
                                std::vector<std::string>& value) {
    CHECK_EQ(row_key.size(), column_key.size());
    value.clear();

    int64_t row = 0;
    int64_t column = 0;
    double result;
    read_lock _lock(KVStorage::_rwmutex);

    value.reserve(row_key.size());

    for (uint64_t i = 0; i < row_key.size(); ++i) {
        row = std::stol(row_key[i]);
        column = std::stol(column_key[i]);

        if (row >= _storage_container.rows() ||
                column >= _storage_container.cols()) {
            LOG(ERROR) << "DENSE MATRIX INDEX ERROR";
        }
        result = _storage_container.coeffRef(row, column);
        value.push_back(std::to_string(result));
    }
}

void SparseMatrix::scan_all(std::vector<std::vector<std::string>>& value) {
    read_lock _lock(KVStorage::_rwmutex);
    value.clear();
    value.resize(3);
    value[0].reserve(1000);
    value[1].reserve(1000);
    value[2].reserve(1000);
    for (int k = 0; k < _storage_container.outerSize(); ++k) {
		for (Eigen::SparseMatrix<double>::InnerIterator it(_storage_container, k); it; ++it) {
			value[2].push_back(std::to_string(it.value()));
            value[0].push_back(std::to_string(it.row()));
            value[1].push_back(std::to_string(it.col()));
   		}
	}
}

void SparseMatrix::scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value) {
    read_lock _lock(KVStorage::_rwmutex);
    value.clear();
    LOG(FATAL) << "NOT IMPLEMENTED \n";

}

Eigen::SparseMatrix<double>* SparseMatrix::storage_ptr(){

    return &_storage_container;
}

}
}


