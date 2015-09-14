/*
 * cpu_functions.cpp
 *
 *  Created on: 14 Sep 2015
 *      Author: sunshine
 */

#include "cpu_functions.h"

namespace ntu {
namespace cap {

CPUFunctions::CPUFunctions() {
    _cpu_functions_p["test"] = test;
}

int64_t CPUFunctions::test (TaskNode new_task) {
    std::cout << "test the function\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    return 1;
}

}
}


