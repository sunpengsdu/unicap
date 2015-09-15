/*
 * node_info.cpp
 *
 *  Created on: 15 Sep 2015
 *      Author: sunshine
 */
#include "node_info.h"
namespace ntu {
namespace cap {

NodeInfo::NodeInfo() {
    _task_tracker_number = 0;
    _ready_task_tracker_number = 0;
    _node_id = 0;
    _node_num = 0;
    _name_length = 0;
    _port = 0;
    _storage_weight = 1;
    _master_port = 9000;
}

NodeInfo& NodeInfo::singleton() {
    static NodeInfo node_info;
    return node_info;
}

}
}



