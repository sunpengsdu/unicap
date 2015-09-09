/*
 * main.cpp
 *
 *  Created on: 2 Sep 2015
 *      Author: sunshine
 */
#include <iostream>
#include <mpi.h>
#include <glog/logging.h>
#include "./task_tracker_server.h"
#include "../common/unicap_client.h"
#include "../common/storage_info.h"
#include "../tools/include/boost/threadpool.hpp"

using namespace  ::ntu::cap;

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


    boost::threadpool::pool task_pool(2);
    std::cout << task_pool.size() << "\n"
              << task_pool.empty() << "\n"
              << task_pool.pending() << "\n"
              << task_pool.active() << "\n";



    server_thread.join();
    MPI_Finalize();
    return 0;
}




