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
#include "image_key_value.h"
namespace ntu {
namespace cap {

typedef unsigned char byte;

InMemoryImage::InMemoryImage():KVStorage() {
}

InMemoryImage::InMemoryImage(const std::string table_name,
                                const int64_t shard_id,
                                const std::string cf_name):
                                KVStorage(table_name, shard_id, cf_name) {
}

InMemoryImage::~InMemoryImage() {
}

int64_t InMemoryImage::vector_put(std::vector<std::string> row_key,
                   std::vector<std::string> column_key,
                   std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);

    std::string single_key;
    for (uint64_t i = 0; i < row_key.size(); ++i) {
        single_key.clear();
        single_key.append(row_key[i]);
        single_key.append("!");
        single_key.append(column_key[i]);

        std::vector<byte> vectordata(value[i].begin(), value[i].end());
        cv::Mat data_mat(vectordata, false);
        auto image = cv::Mat(cv::imdecode(data_mat, CV_LOAD_IMAGE_COLOR));
        if (!image.empty()) {
            _storage_container[single_key] = image;
        }
    }
    return 1;
}

int64_t InMemoryImage::vector_merge(std::vector<std::string> row_key,
                   std::vector<std::string> column_key,
                   std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);
    LOG(FATAL) << "NOT IMPLEMENTED \n";
    return 1;
}

int64_t InMemoryImage::timely_vector_put(std::vector<std::string> row_key,
                          std::vector<std::string> column_key,
                          int64_t time_stamp,
                          std::vector<std::string> value) {
    CHECK_EQ(row_key.size(), column_key.size());
    CHECK_EQ(row_key.size(), value.size());
    write_lock _lock(KVStorage::_rwmutex);
    LOG(FATAL) << "NOT IMPLEMENTED \n";
    return 1;
}

void InMemoryImage::vector_get(std::vector<std::string> row_key,
                                std::vector<std::string> column_key,
                                std::vector<std::string>& value) {
    CHECK_EQ(row_key.size(), column_key.size());
    value.clear();

    std::string single_key;
    std::string single_value;

    read_lock _lock(KVStorage::_rwmutex);

    LOG(FATAL) << "NOT IMPLEMENTED \n";

}

void InMemoryImage::scan_all(std::vector<std::vector<std::string>>& value) {
    read_lock _lock(KVStorage::_rwmutex);
    value.clear();
    value.resize(3);
    std::vector<std::string> tokens;
    std::string single_key;
    std::string single_value;

    LOG(FATAL) << "NOT IMPLEMENTED \n";
}

void InMemoryImage::scan_by_time(int64_t time_stamp, std::vector<std::vector<std::string>>& value) {
    read_lock _lock(KVStorage::_rwmutex);
    value.clear();
    LOG(FATAL) << "NOT IMPLEMENTED \n";

}

std::map<std::string, cv::Mat>* InMemoryImage::storage_ptr(){

    return &_storage_container;
}

}
}



