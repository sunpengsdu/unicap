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
        CPUFunctions::_cpu_functions_p["hello_word"] = hello_word;
    }

    static int64_t hello_word (TaskNode new_task) {
        std::cout << "hello word" << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        return 1;
    }

};

}
}


#endif /* NTU_CAP_UNICAP_COMPUTING_USER_CPU_FUNCTIONS_H_ */
