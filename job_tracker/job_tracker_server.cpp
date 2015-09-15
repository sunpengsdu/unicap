/*
 * job_tracker_server.cpp
 *
 *  Created on: 4 Sep 2015
 *      Author: sunshine
 */
#include "./job_tracker_server.h"

namespace ntu {
namespace cap {

JobTrackerServer::JobTrackerServer() {
    _port       = 9010;
    _thread_num = 1;
}

int64_t JobTrackerServer::set_port(int64_t port) {
    _port = port;
    return 1;
}

int64_t JobTrackerServer::set_thread_num(int64_t thread_num) {
    _thread_num = thread_num;
    return 1;
}

int64_t JobTrackerServer::create_task_tracker_client() {
    for (auto& kvp : NodeInfo::singleton()._task_tracker_info) {
        NodeInfo::singleton()._client_task_tracker[kvp.first] =
            boost::shared_ptr<UnicapClient<TaskTrackerClient>>
            (new UnicapClient<TaskTrackerClient>(kvp.second.host_name,
                    kvp.second.port));
    }
    return 1;
}

int64_t JobTrackerServer::check_client_task_tracker() {

    for (auto i : NodeInfo::singleton()._client_task_tracker) {
        DLOG(INFO) << "CHECK NETWORK CONNECTION: "
                   << i.first
                   << " ("
                   << NodeInfo::singleton()._task_tracker_info[i.first].host_name
                   << ":"
                   << NodeInfo::singleton()._task_tracker_info[i.first].port
                   << ")";
        std::string re;
        i.second->open_transport();
        i.second->method()->ping(re);
        CHECK_EQ(re, "Pong");
        i.second->close_transport();
    }
    return 1;
}

std::thread JobTrackerServer::start() {
    _handler          = boost::shared_ptr<JobTrackerHandler>(new JobTrackerHandler());
    _processor        = boost::shared_ptr<TProcessor>(new JobTrackerProcessor(_handler));
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

}
}


