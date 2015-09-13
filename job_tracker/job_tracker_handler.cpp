/*
 * job_tracker_handler.cpp
 *
 *  Created on: 9 Sep 2015
 *      Author: sunshine
 */
#include "./job_tracker_handler.h"

namespace ntu {
namespace cap {

JobTrackerHandler::JobTrackerHandler() {
    // Your initialization goes here
}

int64_t JobTrackerHandler::register_task_tracker(const int64_t node_id,
        const std::string& node_name,
        const int64_t storage_weight) {

    int64_t available_port = _base_port;

    _register_lock.lock();
    if (NodeInfo::singleton()._task_tracker_info.find(node_id)
            != NodeInfo::singleton()._task_tracker_info.end()) {
        VLOG(0) << "Node ID: " << node_id
                << " Already Exists";
    } else {
        if (NodeInfo::singleton()._physical_node_info.find(node_name)
                != NodeInfo::singleton()._physical_node_info.end()) {
            ++NodeInfo::singleton()._physical_node_info[node_name];
        } else {
            NodeInfo::singleton()._physical_node_info[node_name] = 1;
        }

        available_port = _base_port
                         + NodeInfo::singleton()._physical_node_info[node_name]
                         - 1;

        NodeInfo::singleton()._task_tracker_info[node_id].host_name = node_name;
        NodeInfo::singleton()._task_tracker_info[node_id].port      = available_port;
        ++NodeInfo::singleton()._task_tracker_number;

        for (int i = 0; i < storage_weight; ++i) {
            NodeInfo::singleton()._storage_weight_pool.push_back(node_id);
        }
    }
    _register_lock.unlock();

    VLOG(0) << "Register Node"
            << " -> "
            << node_id
            << "("
            << node_name
            << " : "
            << available_port;

    return NodeInfo::singleton()._task_tracker_info[node_id].port;
}

void JobTrackerHandler::get_all_task_tracker_info(std::map<int64_t,
        TaskTrackerInfo> & _return) {
    _return =  NodeInfo::singleton()._task_tracker_info;
    _register_lock.lock();
    ++NodeInfo::singleton()._ready_task_tracker_number;
    _register_lock.unlock();
}

void JobTrackerHandler::fetch_cpu_task(TaskNode& _return, const int64_t task_tracker_id) {
    // Your implementation goes here
    _return.status = true;
    _return.__set_function_name("test2");
    if (UCPUFunctions::singleton()._cpu_functions_p.find(_return.function_name)
        == CPUFunctions::singleton()._cpu_functions_p.end()) {
        LOG(FATAL) << "FUNCTION "
                   << _return.function_name
                   << " CANNOT FIND";
    }
}

void JobTrackerHandler::fetch_gpu_task(TaskNode& _return, const int64_t task_tracker_id) {
    // Your implementation goes here
    //printf("fetch_gpu_task\n");
}

int64_t JobTrackerHandler::complete_cpu_task(const int64_t stage_id, const int64_t task_id) {
    // Your implementation goes here
    printf("complete_cpu_task\n");
}

int64_t JobTrackerHandler::complete_gpu_task(const int64_t stage_id, const int64_t task_id) {
    // Your implementation goes here
    printf("complete_gpu_task\n");
}


}
}



