/*
 * task_tracker_server.cpp
 *
 *  Created on: 4 Sep 2015
 *      Author: sunshine
 */
#include "./task_tracker_server.h"
namespace ntu{
namespace cap{

TaskTrackerServer::TaskTrackerServer() {
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

int64_t TaskTrackerServer::set_thread_num(int64_t thread_num) {
        _thread_num = thread_num;
        return 1;
    }

int64_t TaskTrackerServer::get_node_num() {
    return _node_num;
}

int64_t TaskTrackerServer::get_node_id() {
        return _node_id;
    }

int64_t TaskTrackerServer::regeister() {
        _client_job_tracker->open_transport();
        _port = _client_job_tracker->method()->register_task_tracker(_node_id, _processor_name, 1);
        VLOG(0) << "Port: " << _port;
        _client_job_tracker->close_transport();
        return 1;
    }

int64_t TaskTrackerServer::fetch_node_info() {
        _client_job_tracker->open_transport();
        _client_job_tracker->method()->get_all_task_tracker_info(NodeInfo::singleton()._task_tracker_info);
        _client_job_tracker->close_transport();
       return 1;
    }

int64_t TaskTrackerServer::create_task_tracker_client() {
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
TaskTrackerServer::get_client_task_tracker() {
        return _client_task_tracker;
    }

int64_t TaskTrackerServer::check_client_task_tracker() {
        VLOG(0) << "CHECK NETWORK CONNECTION";
        for (auto i : _client_task_tracker){
            std::string re;
            i.second->open_transport();
            i.second->method()->ping(re);
            CHECK_EQ(re, "Pong");
            i.second->close_transport();
        }
    }

std::thread TaskTrackerServer::start() {
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

}
}



