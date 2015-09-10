/*
 * cpu_networks.h
 *
 *  Created on: 10 Sep 2015
 *      Author: sunshine
 */

#ifndef UNICAP_TASK_TRACKER_CPU_NETWORKS_H_
#define UNICAP_TASK_TRACKER_CPU_NETWORKS_H_

#include <vector>
#include <thread>
#include <unordered_map>
#include <mutex>
#include "../common/unicap_client.h"

namespace ntu {
namespace cap {

class CPUNetworks {
public:
    static CPUNetworks& singleton() {
        static CPUNetworks cpu_network;
        return cpu_network;
    }

    int64_t create_network(std::thread::id id,
            std::unordered_map<int64_t,
                boost::shared_ptr<UnicapClient<TaskTrackerClient>>> network) {
        _lock.lock();
        _cpu_networks[id] = network;
        _lock.unlock();
        return 1;
    }

    bool check_thread(std::thread::id id) {
        bool flag;
        _lock.lock();
        auto i = _cpu_networks.find(id);
        if (i == _cpu_networks.end()) {
            flag = false;
        } else {
            flag = true;
        }
        _lock.unlock();
        return flag;
    }

    int64_t size() {
        return _cpu_networks.size();
    }

    std::mutex _lock;
    std::unordered_map<std::thread::id, std::unordered_map<int64_t,
            boost::shared_ptr<UnicapClient<TaskTrackerClient>>>>
            _cpu_networks;
};

}
}
#endif /* UNICAP_TASK_TRACKER_CPU_NETWORKS_CPP_ */
