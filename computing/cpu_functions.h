/*
 * cpu_functions.h
 *
 *  Created on: 9 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_COMPUTING_CPU_FUNCTIONS_H_
#define NTU_CAP_UNICAP_COMPUTING_CPU_FUNCTIONS_H_

#include <stdint.h>
#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include "../gen/JobTracker.h"
#include "../gen/TaskTracker.h"
#include "../common/storage_info.h"
#include "../task_tracker/cpu_networks.h"


namespace ntu {
namespace cap {

typedef int64_t (*cpu_function_p)(TaskNode);

class CPUFunctions {
public:

    static CPUFunctions& singleton() {
       static CPUFunctions cpu_function;
       return cpu_function;
    }

    CPUFunctions() {
        _cpu_functions_p["test"] = test;
    }

    static int64_t test (TaskNode new_task) {
        std::cout << "test the function\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        return 1;
    }

    std::map<std::string, cpu_function_p> _cpu_functions_p;
};

}
}

#endif /* NTU_CAPUNICAP_COMPUTING_CPU_FUNCTIONS_H_ */
