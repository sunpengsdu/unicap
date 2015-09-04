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

using namespace  ::ntu::cap;

int main(int argc, char **argv) {

  //google::InitGoogleLogging(argv[0]);
  MPI_Init(&argc, &argv);

  TaskTrackerServer::singleton().regeister();
  MPI_Barrier(MPI_COMM_WORLD);
  //TaskTrackerServer::singleton().set_thread_num(10);
  auto server_thread = TaskTrackerServer::singleton().start();
  TaskTrackerServer::singleton().fetch_node_info();
  MPI_Barrier(MPI_COMM_WORLD);
  TaskTrackerServer::singleton().create_task_tracker_client();
  TaskTrackerServer::singleton().check_client_task_tracker();
  MPI_Barrier(MPI_COMM_WORLD);

  server_thread.join();

  MPI_Finalize();
  return 0;
}




