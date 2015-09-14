/*
 * scheduler.h
 *
 *  Created on: 10 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_JOB_TRACKER_SCHEDULER_H_
#define NTU_CAP_UNICAP_JOB_TRACKER_SCHEDULER_H_

#include <map>
#include <string>
#include "stage.h"

namespace ntu {
namespace cap {

class Scheduler {
public:

    static Scheduler& singleton() {
        static Scheduler scheduler;
        return scheduler;
    }

    int64_t push_back(std::shared_ptr<Stage> new_stage) {
        int64_t id = _stage_pool.size();
        new_stage->_stage_id = id;
        _stage_pool.push_back(new_stage);
        _stage_num = _stage_pool.size();
        return 1;
    }

    int64_t fetch_cpu_task(TaskNode& _return, const int64_t task_tracker_id) {
        for (int i = 0; i < _stage_num; ++i) {
            if (_stage_pool[i]->_complete_task.size() != _stage_pool[i]->size()) {
                _stage_pool[i]->fetch_task(task_tracker_id, _return);
                break;
            }
        }
        return 1;
    }

    //stage_id stage
    std::vector<std::shared_ptr<Stage>> _stage_pool;
    int64_t            _stage_num;
};

}
}

#endif /* UNICAP_JOB_TRACKER_SCHEDULER_H_ */
