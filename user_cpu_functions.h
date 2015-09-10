/*
 * user_cpu_functions.h
 *
 *  Created on: 10 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_COMPUTING_USER_CPU_FUNCTIONS_H_
#define NTU_CAP_UNICAP_COMPUTING_USER_CPU_FUNCTIONS_H_

#include "computing/cpu_functions.h"

namespace ntu {
namespace cap {

class UCPUFunctions : public CPUFunctions {
public:
    static UCPUFunctions& singleton() {
        static UCPUFunctions u_cpu_function;
        return u_cpu_function;
    }

    UCPUFunctions() : CPUFunctions() {
        CPUFunctions::_cpu_functions_p["test2"] = test2;
    }

    static int64_t test2 (TaskNode new_task) {
        std::cout << "test the user function ";
        std::string test;
        CPUNetworks::singleton()._cpu_networks[std::this_thread::get_id()][0]->open_transport();
        CPUNetworks::singleton()._cpu_networks[std::this_thread::get_id()][0]->method()->ping(test);
        CPUNetworks::singleton()._cpu_networks[std::this_thread::get_id()][0]->close_transport();
        std::cout << test << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        return 1;
    }

};

}
}


#endif /* NTU_CAP_UNICAP_COMPUTING_USER_CPU_FUNCTIONS_H_ */
