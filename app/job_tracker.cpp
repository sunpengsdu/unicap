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

    NodeInfo::singleton()._master_port = 34000;
    NodeInfo::singleton()._hdfs_namenode = "BDP-00";
    NodeInfo::singleton()._hdfs_namenode_port = 9000;
    NodeInfo::singleton()._root_dir = "/unicap/";
    NodeInfo::singleton()._app_name = "test";

    std::thread server_side_thread;
    server_side_thread = DAG::start_job_tracker(10);

    //load_local_file("./data", "s", "p");
    //load_hdfs_file("/dataset/wikipedia_300GB/file100005", "s", "p");
    //load_hdfs_file("/dataset/wikipedia_300GB/file100005", "s", "p", 1024*1024*32, StorageType::type::HdfsKeyValue);
    //load_hdfs_file("/dataset/wikipedia_300GB/file100005", "s", "p", 1024*1024*32);
//    DAG::load_hdfs_file("/dataset/wikipedia_300GB/file100005", "s", "p", 1024*1024*32);

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

    std::vector<std::string> row;
    std::vector<std::string> column;
    std::vector<std::string> value;
    row.push_back("a");
    row.push_back("b");
    column.push_back("1");
    column.push_back("2");
    value.push_back("a1");
    value.push_back("b2");
    Storage::vector_put("a", "a", 0, row, column, value);


    std::vector<std::string> return_value1;

    Storage::vector_get("a","a", 0, row, column, return_value1);

    for (uint64_t j=0; j<return_value1.size(); ++j) {
        std::cout << return_value1[j] << "\n";
    }
    std::vector<std::vector<std::string> > return_value2;

    server_side_thread.join();
    return 0;
}
