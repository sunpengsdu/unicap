/*
 * job_tracker_server.h
 *
 *  Created on: 2 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_JOB_TRACKER_JOB_TRACKER_SERVER_H_
#define NTU_CAP_UNICAP_JOB_TRACKER_JOB_TRACKER_SERVER_H_

#include <stdint.h>
#include <thread>
#include <iostream>

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

#include "./job_tracker_handler.h"
#include "../gen/JobTracker.h"
#include "../gen/TaskTracker.h"
#include "../common/unicap_client.h"
#include "../common/table.h"
#include "../common/column_family.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

namespace ntu {
namespace cap {

class JobTrackerServer {
public:
    JobTrackerServer() {
        _port       = 9010;
        _thread_num = 1;
    }

    static JobTrackerServer& singleton() {
        static JobTrackerServer server;
        return server;
    }

    int64_t set_port(int64_t port) {
        _port = port;
        return 1;
    }

    int64_t set_node_num(int64_t node_num) {
        _thread_num = node_num;
        return 1;
    }

    int64_t set_thread_num(int64_t thread_num) {
        _thread_num = thread_num;
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

    const std::map<int64_t,  boost::shared_ptr<UnicapClient<TaskTrackerClient>> >&
    get_client_task_tracker() {
        return _client_task_tracker;
    }

    std::thread start() {
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

    static int64_t serve(boost::shared_ptr<TThreadPoolServer> &server) {
        server->serve();
        return 1;
    }

private:
    int64_t _port;
    int64_t _thread_num;

    boost::shared_ptr<JobTrackerHandler>  _handler;
    boost::shared_ptr<TProcessor>         _processor;
    boost::shared_ptr<TServerTransport>   _serverTransport;
    boost::shared_ptr<TTransportFactory>  _transportFactory;
    boost::shared_ptr<TProtocolFactory>   _protocolFactory;
    boost::shared_ptr<ThreadManager>      _threadManager;

    boost::shared_ptr<PosixThreadFactory> _threadFactory;
    boost::shared_ptr<TThreadPoolServer>  _server;

    std::map<int64_t,  boost::shared_ptr<UnicapClient<TaskTrackerClient>> > _client_task_tracker;

};

}//end namspace ntu
}//end namespace cap

#endif /* UNICAP_JOB_TRACKER_JOB_TRACKER_SERVER_H_ */
