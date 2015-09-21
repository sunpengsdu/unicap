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
#include <iostream>
#include <mpi.h>
#include <glog/logging.h>
#include "cpu_worker.h"
#include "task_tracker_server.h"

using namespace ntu;
using namespace cap;

std::thread task_tracker_initial(int64_t thread_num) {
    TaskTrackerServer::singleton().regeister();
    MPI_Barrier(MPI_COMM_WORLD);

    TaskTrackerServer::singleton().set_thread_num(thread_num);
    auto server_thread = TaskTrackerServer::singleton().start();
    MPI_Barrier(MPI_COMM_WORLD);

    TaskTrackerServer::singleton().fetch_node_info();
    TaskTrackerServer::singleton().create_task_tracker_client();
//    TaskTrackerServer::singleton().check_client_task_tracker();
    MPI_Barrier(MPI_COMM_WORLD);

    return server_thread;
}


int main(int argc, char **argv) {

    google::InitGoogleLogging(argv[0]);
    google::LogToStderr();

    NodeInfo::singleton()._master_host_name   = "localhost";
    NodeInfo::singleton()._master_port        = 34000;
    NodeInfo::singleton()._hdfs_namenode      = "BDP-00";
    NodeInfo::singleton()._hdfs_namenode_port = 9000;
    NodeInfo::singleton()._root_dir           = "/unicap/";
    NodeInfo::singleton()._app_name           = "test";

    int64_t cpu_network_threads = 10;
    int64_t cpu_worker_num = 2;

    MPI_Init(&argc, &argv);
    auto server_thread = task_tracker_initial(cpu_network_threads);

    CPUWorker client(cpu_worker_num);
    auto work_cpu_thread   = client.cpu_worker_start();

    server_thread.join();
    work_cpu_thread.join();
    MPI_Finalize();
    return 0;
}




