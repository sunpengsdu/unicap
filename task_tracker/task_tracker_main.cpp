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

#include "../computing/cpu_functions.h"

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

int64_t execute_tasks(int64_t thread_num) {

    TaskNode new_task;
    std::string function_name;
    boost::threadpool::pool task_pool(thread_num);

   // NodeInfo::singleton()._client_job_tracker->open_transport();

    while(true) {

        if(task_pool.active() == task_pool.size()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            continue;
        }

        NodeInfo::singleton()._client_job_tracker->open_transport();
        NodeInfo::singleton()._client_job_tracker ->
                method() ->fetch_task(new_task, NodeInfo::singleton()._node_id);
        NodeInfo::singleton()._client_job_tracker ->
                close_transport();

        if (new_task.status) {
            function_name = new_task.function_name;
            auto i = std::bind(CPUFunctions::singleton()._cpu_functions_p[function_name],
                                new_task);
            task_pool.schedule(i);

        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
    return 1;
}

std::thread task_tracker_start(int64_t thread_num) {
    auto work_thread = std::thread(execute_tasks, thread_num);
    return work_thread;
}


int main(int argc, char **argv) {

    //google::InitGoogleLogging(argv[0]);
    MPI_Init(&argc, &argv);
    auto server_thread = task_tracker_initial(10);
    auto work_thread   = task_tracker_start(2);

    server_thread.join();
    work_thread.join();
    MPI_Finalize();
    return 0;
}




