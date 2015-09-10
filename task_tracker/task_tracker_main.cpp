/*
 * main.cpp
 *
 *  Created on: 2 Sep 2015
 *      Author: sunshine
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
    TaskTrackerServer::singleton().check_client_task_tracker();
    MPI_Barrier(MPI_COMM_WORLD);

    return server_thread;
}


int main(int argc, char **argv) {

    //google::InitGoogleLogging(argv[0]);
    MPI_Init(&argc, &argv);
    auto server_thread = task_tracker_initial(10);

    TaskTrackerWorker client(2);
    auto work_cpu_thread   = client.cpu_worker_start();

    server_thread.join();
    work_cpu_thread.join();
    MPI_Finalize();
    return 0;
}




