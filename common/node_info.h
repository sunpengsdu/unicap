/*
 * node_info.h
 *
 *  Created on: 3 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_JOB_TRACKER_NODE_INFO_H_
#define NTU_CAP_UNICAP_JOB_TRACKER_NODE_INFO_H_

#include <map>
#include <string>
#include <vector>
#include <utility>
#include "../gen/JobTracker.h"
#include "../gen/TaskTracker.h"

namespace ntu {
namespace cap {

class NodeInfo {
public:
    NodeInfo() {
        _task_tracker_number = 0;
        _ready_task_tracker_number = 0;
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
};

}
}
#endif /* UNICAP_JOB_TRACKER_NODE_INFO_H_ */
