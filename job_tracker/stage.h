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

    Stage(std::string func_name,
            std::string dst_table,
            std::string dst_cf,
            int64_t task_num) {
        _function_name = func_name;
        _src_table  = "";
        _src_cf     = "";
        _dst_table  = dst_table;
        _dst_cf     = dst_cf;
        _size       = task_num;
    }

    Stage(std::string func_name,
            std::string src_table,
            std::string src_cf,
            std::string dst_table,
            std::string dst_cf) {
        _function_name = func_name;
        _src_table  = src_table;
        _src_cf     = src_cf;
        _dst_table  = dst_table;
        _dst_cf     = dst_cf;
        _size       = StorageInfo::singleton().
                        _table_info[src_table].
                        _table_property.
                        shard_num;
    }

    int64_t size() {
        return _size;
    }

    int64_t push_task(int64_t node_id) {
        TaskNode new_task;
        --_size;
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
