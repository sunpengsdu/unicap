/*
 * task_tracker_cleint.h
 *
 *  Created on: 10 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_CPU_WORKER_H_
#define NTU_CAP_UNICAP_CPU_WORKER_H_

#include <vector>
#include "../common/unicap_client.h"
#include "../common/storage_info.h"
#include "../tools/include/boost/threadpool.hpp"
#include "../computing/cpu_functions.h"
#include "../user_cpu_functions.h"
#include "cpu_networks.h"

namespace ntu {
namespace cap {

class CPUWorker {

public:

    static CPUWorker& singleton() {
        static CPUWorker client;
        return client;
    }

    CPUWorker();

    CPUWorker(int64_t worker_number);

    static int64_t cpu_execute_tasks(int64_t worker_number);

    static int64_t functions(std::string function_name, TaskNode task);

    std::thread cpu_worker_start();

    static int64_t create_network();

    int64_t _worker_number;

};

}
}

#endif /* NTU_CAP_UNICAP_CPU_WORKER_H_ */
