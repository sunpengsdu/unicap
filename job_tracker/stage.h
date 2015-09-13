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

namespace ntu {
namespace cap {

class Stage {
public:

    Stage() {
        _function_name = "";
        _src_table  = "";
        _src_cf     = "";
        _dst_table  = "";
        _dst_cf     = "";
        _size       = 0;
    }

    Stage(std::string func_name) {
        _function_name = func_name;
        _src_table  = "";
        _src_cf     = "";
        _dst_table  = "";
        _dst_cf     = "";
        _size       = 0;
    }

    int64_t set_function_name(std::string function_name) {
        _function_name = function_name;
        return 1;
    }

    int64_t set_src_table(std::string src_table) {
       _src_table = src_table;
       return 1;
    }

    int64_t add_src_cf(std::string src_cf) {

        return 1;
    }

    int64_t size() {
        return _size;
    }

    int64_t push_task(int64_t node_id) {
        TaskNode new_task;
        return 1;
    }

    std::string _function_name;
    std::string _src_table;
    std::string _src_cf;
    std::string _dst_table;
    std::string _dst_cf;
    std::vector<int64_t> _source_shard;
    int64_t _size;
};

}
}
#endif /* UNICAP_JOB_TRACKER_STAGE_H_ */
