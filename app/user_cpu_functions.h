/*
 *Copyright 2015 NTU (http://www.ntu.edu.sg/)
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
*/

#ifndef NTU_CAP_UNICAP_COMPUTING_USER_CPU_FUNCTIONS_H_
#define NTU_CAP_UNICAP_COMPUTING_USER_CPU_FUNCTIONS_H_

#include "../src/computing/cpu_functions.h"

namespace ntu {
namespace cap {

class UCPUFunctions : public CPUFunctions {
public:
    static UCPUFunctions& singleton() {
        static UCPUFunctions u_cpu_function;
        return u_cpu_function;
    }

    UCPUFunctions() : CPUFunctions() {
        CPUFunctions::_cpu_functions_p["hello_world"] = hello_world;
    }

    static int64_t hello_world (TaskNode new_task) {
        std::cout << "hello world" << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        return 1;
    }

};

}
}


#endif /* NTU_CAP_UNICAP_COMPUTING_USER_CPU_FUNCTIONS_H_ */
