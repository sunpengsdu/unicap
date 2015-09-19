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
#include "job_tracker/job_tracker_function.h"

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
    server_side_thread = start_job_tracker(10);

    //load_local_file("./data", "s", "p");
    //load_hdfs_file("/dataset/wikipedia_300GB/file100005", "s", "p");
    //load_hdfs_file("/dataset/wikipedia_300GB/file100005", "s", "p", 1024*1024*32, StorageType::type::HdfsKeyValue);
    //load_hdfs_file("/dataset/wikipedia_300GB/file100005", "s", "p", 1024*1024*32);
    load_hdfs_file("/dataset/wikipedia_300GB/file100005", "s", "p", 1024*1024*32);

    KeyPartition rrr;

    rrr.__set_partition_algo(KeyPartitionAlgo::HashingPartition);
    create_table("a", 10, rrr);
    create_cf("a", "a", StorageType::InMemoryKeyValue);

/*
    std::shared_ptr<Stage>stage_1 = std::shared_ptr<Stage>(new Stage());
    stage_1->set_function_name("hello_world");
    stage_1->non_src(100);
   // stage_2->set_dst("a", "a");
    Scheduler::singleton().push_back(stage_1);
*/

    save_to_hdfs("s", "p");

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

//    std::cout << StorageInfo::singleton()._table_info["s"]._table_property.shard_num << "\n"; 

    Storage::scan_all("s", "p_hdfs_property", 0, return_value2);
 //   std::cout << return_value2[2][0].size() << "\n";

    std::cout << "\n";
    for (uint64_t j=0; j<return_value2[0].size(); ++j) {
        std::cout << return_value2[0][j] << ":"
                  << return_value2[1][j] << "\n";
                 // << return_value2[2][j] << "\n";
    }

// create_cf("a", "b", StorageType::CommonKeyValue);


// create_task()


// foo.compare_exchange_weak(&i, j, std::memory_order_release, std::memory_order_release);

// std::atomic::compare_exchange_weak(std::ref(0), 1, std::memory_order_release, std::memory_order_release);

    server_side_thread.join();
    return 0;
}
