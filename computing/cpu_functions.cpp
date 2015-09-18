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

#include "cpu_functions.h"

namespace ntu {
namespace cap {

CPUFunctions::CPUFunctions() {
    _cpu_functions_p["test"] = test;
    _cpu_functions_p["load_hdfs"] = load_hdfs;
}

int64_t CPUFunctions::test (TaskNode new_task) {
    std::cout << "test the function\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    return 1;
}

int64_t CPUFunctions::load_hdfs (TaskNode new_task) {

    struct hdfsBuilder *builder = hdfsNewBuilder();
    hdfsBuilderSetNameNode(builder, NodeInfo::singleton()._hdfs_namenode.c_str());
    hdfsBuilderSetNameNodePort(builder, NodeInfo::singleton()._hdfs_namenode_port);
    hdfsFS fs = hdfsBuilderConnect(builder);

    std::vector<std::vector<std::string>> value;

    StorageInfo::singleton()._cf_ptr[new_task.src_table_name]
                                 [new_task.src_shard_id]
                                 [new_task.src_cf_name] ->
                                 scan_all(value);
    std::cout << value[0][0] << "->" << value[0][1] << "\n";

    hdfsDisconnect(fs);
    return 1;
}


}
}


