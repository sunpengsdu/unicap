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
#include "../src/job_tracker/DAG.h"

using namespace  ::ntu::cap;

int main(int argc, char **argv) {
    google::InitGoogleLogging(argv[0]);
    google::LogToStderr();
    std::thread jobtracker = DAG::initial();

    DAG::create_table("test_dense_matrix", 10);
    DAG::create_cf("test_dense_matrix",
                "test_dense_matrix",
                StorageType::SparseMatrix,
                std::make_pair(100, 100));

    std::vector<std::vector<std::string>> dense_result;



    std::vector<std::string> row;
    std::vector<std::string> column;
    std::vector<std::string> value;
    row.push_back("0");
    row.push_back("1");
    column.push_back("0");
    column.push_back("1");
    value.push_back(std::to_string(1.11));
    value.push_back(std::to_string(2.22));
    Storage::vector_put("test_dense_matrix", "test_dense_matrix", 0, row, column, value);



    Storage::scan_all("test_dense_matrix", "test_dense_matrix", 0, dense_result);

    for (int i = 0; i < dense_result[0].size(); ++i) {
        std::cout << dense_result[0][i] 
                  << "-"
                  << dense_result[1][i]
                  << "->"
                  << dense_result[2][i]
                  << "\n";
    }

    DAG::load_hdfs_img("/imagenet/ILSVRC2014_DET_train/n07747607", "im", "ttt", 16*1024*1024);

    KeyPartition rrr;

    rrr.__set_partition_algo(KeyPartitionAlgo::HashingPartition);
    DAG::create_table("a", 10, rrr);
    DAG::create_cf("a", "a", StorageType::InMemoryKeyValue);

    IntermediateResult<int, int, std::string> inter_store("a");
    inter_store.push_back(1, 2, "sd");
    inter_store.push_back(1, 2, "a");
    inter_store.push_back(1, 1, "3");
    inter_store.push_back(2, 1, "s");
    inter_store.merge_data();

    int ccc = 0;
    for (auto& i : inter_store._sharded_result_container) {
        for (auto& j : i) {
            for (auto& k : j.second)
                std::cout << ccc << ":"<< j.first << "->" << k.first << "->" << k.second << "\n";
        }
        ++ccc;
    }



    std::vector<std::string> return_value1;

    Storage::vector_get("test_dense_matrix","test_dense_matrix", 0, row, column, return_value1);

    for (uint64_t j=0; j<return_value1.size(); ++j) {
        std::cout << return_value1[j] << "\n";
    }
    std::vector<std::vector<std::string> > return_value2;

    jobtracker.join();
    return 0;
}
