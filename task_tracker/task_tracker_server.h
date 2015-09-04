/*
 * task_tracker_server.h
 *
 *  Created on: 2 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_TASK_TRACKER_TASK_TRACKER_SERVER_H_
#define NTU_CAP_UNICAP_TASK_TRACKER_TASK_TRACKER_SERVER_H_

#include <stdint.h>
#include <thread>
#include <iostream>
#include <mpi.h>

#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PlatformThreadFactory.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/TToString.h>

#include "./task_tracker_handler.h"
#include "../gen/TaskTracker.h"
#include "../gen/JobTracker.h"
#include "../common/unicap_client.h"
#include "../common/table.h"
#include "../common/column_family.h"

#define JOBTRACKERNAME "localhost"
#define JOBTRACKERPORT 9000

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

namespace ntu {
namespace cap {

class TaskTrackerServer {
public:
    TaskTrackerServer() {
        _port        = 9010;
        _node_num    = 0;
        _node_id     = 0;
        _thread_num  = 0;
        _name_length = 0;

        MPI_Comm_rank(MPI_COMM_WORLD, &_node_id);
        MPI_Comm_size(MPI_COMM_WORLD, &_node_num);
        MPI_Get_processor_name(_processor_name, &_name_length);
        _host_name = std::string(_processor_name, _name_length);
        _thread_num = _node_num;
        _client_job_tracker = boost::shared_ptr<UnicapClient<JobTrackerClient>>
                        (new UnicapClient<JobTrackerClient>(JOBTRACKERNAME, JOBTRACKERPORT));
    }

    static TaskTrackerServer& singleton() {
        static TaskTrackerServer server;
        return server;
    }

    int64_t set_thread_num(int64_t thread_num) {
        _thread_num = thread_num;
        return 1;
    }

    int64_t get_node_num() {
        return _node_num;
    }

    int64_t get_node_id() {
        return _node_id;
    }

    int64_t regeister() {
        _client_job_tracker->open_transport();
        _port = _client_job_tracker->method()->register_task_tracker(_node_id, _processor_name, 1);
        VLOG(0) << "Port: " << _port;
        _client_job_tracker->close_transport();
        return 1;
    }

    int64_t fetch_node_info() {
        _client_job_tracker->open_transport();
        _client_job_tracker->method()->get_all_task_tracker_info(NodeInfo::singleton()._task_tracker_info);
        _client_job_tracker->close_transport();
       return 1;
    }

    int64_t create_task_tracker_client() {
        for (auto& kvp : NodeInfo::singleton()._task_tracker_info) {
            std::cout << kvp.first;
            _client_task_tracker[kvp.first] =
                    boost::shared_ptr<UnicapClient<TaskTrackerClient>>
                    (new UnicapClient<TaskTrackerClient>(kvp.second.host_name,
                                                        kvp.second.port));
        }
        return 1;
    }

    const std::map<int64_t, boost::shared_ptr<UnicapClient<TaskTrackerClient>> >&
    get_client_task_tracker() {
        return _client_task_tracker;
    }

    int64_t check_client_task_tracker() {
        VLOG(0) << "CHECK NETWORK CONNECTION";
        for (auto i : _client_task_tracker){
            std::string re;
            i.second->open_transport();
            i.second->method()->ping(re);
            CHECK_EQ(re, "Pong");
            i.second->close_transport();
        }
    }

    std::thread start() {
        _handler          = boost::shared_ptr<TaskTrackerHandler>(new TaskTrackerHandler());
        _processor        = boost::shared_ptr<TProcessor>(new TaskTrackerProcessor(_handler));
        _serverTransport  = boost::shared_ptr<TServerTransport>(new TServerSocket(_port));
        _transportFactory = boost::shared_ptr<TTransportFactory>(new TBufferedTransportFactory());
        _protocolFactory  = boost::shared_ptr<TProtocolFactory>(new TBinaryProtocolFactory());

        _threadManager    = boost::shared_ptr<ThreadManager>(ThreadManager::newSimpleThreadManager(_thread_num));
        _threadFactory    = boost::shared_ptr<PosixThreadFactory>(new PosixThreadFactory());

        _threadManager->threadFactory(_threadFactory);
        _threadManager->start();
        _server =  boost::shared_ptr<TThreadPoolServer>(new TThreadPoolServer(_processor,
                                        _serverTransport,
                                        _transportFactory,
                                        _protocolFactory,
                                        _threadManager));
        std::thread thread_server(serve, std::ref(_server));

        return thread_server;
    }

    static int64_t serve(boost::shared_ptr<TThreadPoolServer> &server) {
        VLOG(0) << "START TASK TRACKER";
        server->serve();
        VLOG(0) << "STOP TASK TRACKER";
        return 1;
    }

private:
    int64_t _port;
    int64_t _thread_num;

    int _node_id, _node_num, _name_length;
    char _processor_name[MPI_MAX_PROCESSOR_NAME];
    std::string _host_name;

    boost::shared_ptr<UnicapClient<JobTrackerClient>> _client_job_tracker;
    std::map<int64_t,  boost::shared_ptr<UnicapClient<TaskTrackerClient>> > _client_task_tracker;

    boost::shared_ptr<TaskTrackerHandler> _handler;
    boost::shared_ptr<TProcessor>         _processor;
    boost::shared_ptr<TServerTransport>   _serverTransport;
    boost::shared_ptr<TTransportFactory>  _transportFactory;
    boost::shared_ptr<TProtocolFactory>   _protocolFactory;
    boost::shared_ptr<ThreadManager>      _threadManager;

    boost::shared_ptr<PosixThreadFactory> _threadFactory;
    boost::shared_ptr<TThreadPoolServer>  _server;
};

}//end namspace ntu
}//end namespace cap

#endif /* UNICAP_TASK_TRACKER_TASK_TRACKER_SERVER_H_ */
