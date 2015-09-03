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
#include <utility>
#include "../gen/JobTracker.h"
#include "../gen/TaskTracker.h"

namespace ntu {
namespace cap {

class NodeInfo {
public:
    NodeInfo() { }

    static NodeInfo& singleton() {
        static NodeInfo node_info;
        return node_info;
    }
    //map<node_id, pair<hostname, port>>
    std::map<int64_t, TaskTrackerInfo> _task_tracker_info;
    //number of task trackers in each physical node
    std::map<std::string, int64_t> _physical_node_info;
};

}
}
#endif /* UNICAP_JOB_TRACKER_NODE_INFO_H_ */
