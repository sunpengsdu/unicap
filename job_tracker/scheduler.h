/*
 * scheduler.h
 *
 *  Created on: 10 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_JOB_TRACKER_SCHEDULER_H_
#define NTU_CAP_UNICAP_JOB_TRACKER_SCHEDULER_H_

#include "stage.h"

class Scheduler {
public:

    static Scheduler& singleton() {
        static Scheduler scheduler;
        return scheduler;
    }

std::vector<>
};


#endif /* UNICAP_JOB_TRACKER_SCHEDULER_H_ */
