/*
 * task_tracker_client.cpp
 *
 *  Created on: 10 Sep 2015
 *      Author: sunshine
 */
#include "cpu_worker.h"

namespace ntu {
namespace cap {

TaskTrackerWorker::TaskTrackerWorker() {
    _worker_number = 1;
}

TaskTrackerWorker::TaskTrackerWorker(int64_t worker_number) {
        _worker_number = worker_number;
}

int64_t TaskTrackerWorker::create_network() {

    std::thread::id id = std::this_thread::get_id();

    if ( CPUNetworks::singleton().check_thread(id)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return 1;
    }
    std::unordered_map<int64_t,
                   boost::shared_ptr<UnicapClient<TaskTrackerClient>>> network;
    for (auto& kvp : NodeInfo::singleton()._task_tracker_info) {
        network[kvp.first] =
           boost::shared_ptr<UnicapClient<TaskTrackerClient>>
               (new UnicapClient<TaskTrackerClient>(kvp.second.host_name,
                                               kvp.second.port));
    }
    CPUNetworks::singleton().create_network(id, network);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    VLOG(0) << "CREATE STORAGE NETWORK FOR THREAD " << id;

    return 1;
}

int64_t TaskTrackerWorker::cpu_execute_tasks(int64_t worker_number) {

    TaskNode new_task;
    std::string function_name;
    boost::threadpool::pool task_pool(worker_number);
    int try_num = 0;

    while (CPUNetworks::singleton().size() != worker_number) {
        for (int i = 0; i < worker_number*1.2; ++i) {
            task_pool.schedule(create_network);
        }
        task_pool.wait();
        ++try_num;
        if (try_num > 5) {
            LOG(FATAL) << "CANNOT CREATE ALL STOAGE NETWORK";
        }
    }

    while(true) {

        if(task_pool.active() == task_pool.size()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            continue;
        }

        NodeInfo::singleton()._client_job_tracker->open_transport();
        NodeInfo::singleton()._client_job_tracker ->
                method() ->fetch_cpu_task(new_task, NodeInfo::singleton()._node_id);
        NodeInfo::singleton()._client_job_tracker ->
                close_transport();

        if (new_task.status) {
            function_name = new_task.function_name;
            auto i = std::bind(UCPUFunctions::singleton()._cpu_functions_p[function_name],
                                new_task);

            task_pool.schedule(i);

        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
    return 1;
}

std::thread TaskTrackerWorker::cpu_worker_start() {
    auto work_thread = std::thread(cpu_execute_tasks, _worker_number);
    return work_thread;
}

}
}

