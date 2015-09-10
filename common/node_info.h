/*
 * node_info.h
 *
 *  Created on: 3 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_JOB_TRACKER_NODE_INFO_H_
#define NTU_CAP_UNICAP_JOB_TRACKER_NODE_INFO_H_

#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>
#include "../gen/JobTracker.h"
#include "../gen/TaskTracker.h"
#include "./unicap_client.h"

namespace ntu {
namespace cap {

class NodeInfo {
public:
    NodeInfo() {
        _task_tracker_number = 0;
        _ready_task_tracker_number = 0;
        _node_id = 0;
        _node_num = 0;
        _name_length = 0;
        _port = 0;
        _storage_weight = 1;
    }

    static NodeInfo& singleton() {
        static NodeInfo node_info;
        return node_info;
    }
    //map<node_id, pair<hostname, port>>
    std::map<int64_t, TaskTrackerInfo> _task_tracker_info;
    //number of task trackers in each physical node
    std::map<std::string, int64_t> _physical_node_info;
    int64_t _task_tracker_number;
    int64_t _ready_task_tracker_number;

    std::vector<int64_t> _storage_weight_pool;

    int _node_id, _node_num, _name_length, _port, _storage_weight;
    char _processor_name[256];
    std::string _host_name;

    boost::shared_ptr<UnicapClient<JobTrackerClient>> _client_job_tracker;
    std::unordered_map<int64_t,
                boost::shared_ptr<UnicapClient<TaskTrackerClient>> >
                _client_task_tracker;
};

}
}
#endif /* UNICAP_JOB_TRACKER_NODE_INFO_H_ */
