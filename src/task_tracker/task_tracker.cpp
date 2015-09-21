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
#include "../tools/include/yaml-cpp/yaml.h"

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


    YAML::Node config = YAML::LoadFile("../etc/unicap.yaml");
    const std::string application_name = config["application_name"].as<std::string>();
    const std::string jobtracker_host = config["jobtracker_host"].as<std::string>();
    const int64_t jobtracker_port = config["jobtracker_port"].as<int64_t>();
    const std::string hdfs_namenode_host = config["hdfs_namenode_host"].as<std::string>();
    const int64_t hdfs_namenode_port = config["hdfs_namenode_port"].as<int64_t>();
    const std::string hdfs_output_dir = config["hdfs_output_dir"].as<std::string>();
    const int64_t tasktracker_worker_threads = config["tasktracker_worker_threads"].as<int64_t>();
    const int64_t tasktracker_network_threads = config["tasktracker_network_threads"].as<int64_t>();

    NodeInfo::singleton()._app_name = application_name;
    NodeInfo::singleton()._master_host_name = jobtracker_host;
    NodeInfo::singleton()._master_port = jobtracker_port;
    NodeInfo::singleton()._hdfs_namenode = hdfs_namenode_host;
    NodeInfo::singleton()._hdfs_namenode_port = hdfs_namenode_port;
    NodeInfo::singleton()._root_dir = hdfs_output_dir;

    LOG(INFO) << "APPLICATION NAME: "            << application_name;
    LOG(INFO) << "JOBTRACKER HOSTNAME: "         << jobtracker_host;
    LOG(INFO) << "JOBTRACKER PORT: "             << jobtracker_port;
    LOG(INFO) << "HDFS NAMENODE HOSTNAME: "      << hdfs_namenode_host;
    LOG(INFO) << "HDFS NAMENODE PORT: "          << hdfs_namenode_port;
    LOG(INFO) << "HDFS OUTPUT DIR: "             << hdfs_output_dir;
    LOG(INFO) << "TASKTRACKER WORKER THREADS: "  << tasktracker_worker_threads;
    LOG(INFO) << "TASKTRACKER NETWORK THREADS: " << tasktracker_network_threads;

    MPI_Init(&argc, &argv);
    auto server_thread = task_tracker_initial(tasktracker_network_threads);

    CPUWorker client(tasktracker_worker_threads);
    auto work_cpu_thread = client.cpu_worker_start();

    server_thread.join();
    work_cpu_thread.join();
    MPI_Finalize();
    return 0;
}




