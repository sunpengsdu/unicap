/*
 * stage.h
 *
 *  Created on: 10 Sep 2015
 *      Author: sunshine
 */

#ifndef UNICAP_JOB_TRACKER_STAGE_H_
#define UNICAP_JOB_TRACKER_STAGE_H_

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <mutex>
#include <glog/logging.h>
#include "../common/table.h"
#include "../common/column_family.h"
#include "../common/storage_info.h"
#include "../user_cpu_functions.h"

namespace ntu {
namespace cap {

class Stage {
public:

    Stage();

    int64_t set_function_name(std::string function_name);

    int64_t set_src(std::string src_table, std::vector<std::string> src_cf);

    int64_t non_src(int64_t task_num);

    int64_t set_dst(std::string dst_table, std::string dst_cf);

    uint64_t size();

    int64_t fetch_task(int64_t node_id, TaskNode &new_task);

    int64_t complete_task(int64_t task_id);

   // static int64_t _stage_num;
    int64_t     _stage_id;
    std::string _function_name;
    std::string _src_table;
    std::vector<std::string> _src_cf;
    std::string _dst_table;
    std::string _dst_cf;

    uint64_t _size;

    //task id - shard id - cf name
    std::map<int64_t, std::pair<int64_t, std::string>> _wait_task;
    std::map<int64_t, std::pair<int64_t, std::string>> _executing_task;
    std::map<int64_t, std::pair<int64_t, std::string>> _complete_task;

    std::map<int64_t, std::vector<int64_t>> _shard_allocation ;

    std::mutex _lock;
};

}
}
#endif /* UNICAP_JOB_TRACKER_STAGE_H_ */
