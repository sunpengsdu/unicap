/*
 * job_tracker_function.cpp
 *
 *  Created on: 4 Sep 2015
 *      Author: sunshine
 */
#include "./job_tracker_function.h"

#define JOBTRACKERNAME "localhost"
#define JOBTRACKERPORT 9000

namespace ntu {
namespace cap {

std::thread start_job_tracker(int64_t thread_num) {

    JobTrackerServer::singleton().set_port(JOBTRACKERPORT);
    JobTrackerServer::singleton().set_thread_num(thread_num);
    auto server_thread = JobTrackerServer::singleton().start();

    while(NodeInfo::singleton()._ready_task_tracker_number
          != NodeInfo::singleton()._task_tracker_number
          || NodeInfo::singleton()._ready_task_tracker_number == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
    JobTrackerServer::singleton().create_task_tracker_client();
    JobTrackerServer::singleton().check_client_task_tracker();

    return server_thread;
}

int64_t create_table(const std::string& table_name,
                    const int64_t shard_num) {

    Table new_table(table_name, shard_num);
    new_table.allocate_shard();

    if (StorageInfo::singleton()._table_info.find(table_name)
            != StorageInfo::singleton()._table_info.end()) {
        LOG(FATAL) << "TABLE ALREADY EXISTS !";
    }

    StorageInfo::singleton()._table_info[table_name] = new_table;

    for (auto i : NodeInfo::singleton()._client_task_tracker){
         i.second->open_transport();
         i.second->method()->create_table(new_table._table_property);
         i.second->close_transport();
     }

    VLOG(0) << "CREATE TABLE " << table_name;
    return 1;
}

int64_t create_table(const std::string& table_name,
                    const int64_t shard_num,
                    const KeyPartition partition) {

    Table new_table(table_name, shard_num, partition);
    new_table.allocate_shard();

    if (StorageInfo::singleton()._table_info.find(table_name)
            != StorageInfo::singleton()._table_info.end()) {
        LOG(FATAL) << "TABLE ALREADY EXISTS !";
    }

    StorageInfo::singleton()._table_info[table_name] = new_table;

    for (auto i : NodeInfo::singleton()._client_task_tracker){
         i.second->open_transport();
         i.second->method()->create_table(new_table._table_property);
         i.second->close_transport();
     }

    VLOG(0) << "CREATE TABLE " << table_name;
    return 1;
}

int64_t create_table(const std::string& table_name,
                    const Table& base_table) {

    Table new_table(table_name, base_table);

    if (StorageInfo::singleton()._table_info.find(table_name)
            != StorageInfo::singleton()._table_info.end()) {
        LOG(FATAL) << "TABLE ALREADY EXISTS !";
    }

    StorageInfo::singleton()._table_info[table_name] = new_table;

    for (auto i : NodeInfo::singleton()._client_task_tracker){
         i.second->open_transport();
         i.second->method()->create_table(new_table._table_property);
         i.second->close_transport();
     }

    VLOG(0) << "CREATE TABLE " << table_name;
    return 1;
}

int64_t create_cf(const std::string& table_name,
                const std::string cf_name,
                const StorageType::type cf_type) {

    ColumnFamily new_cf(cf_name, cf_type);

    for (auto& exist_cf : StorageInfo::singleton()._cf_info[table_name]) {
        if (exist_cf.first == cf_name) {
            LOG(FATAL) << "CF ALREADY EXISTS !";
        }
    }

    StorageInfo::singleton()._cf_info[table_name][cf_name] = new_cf;

    for (auto i : NodeInfo::singleton()._client_task_tracker){
           i.second->open_transport();
           i.second->method()->create_cf(table_name, new_cf._cf_property);
           i.second->close_transport();
       }

    VLOG(0) << "CREATE CF " << cf_name << " FOR TABLE " << table_name;
    return 1;
}

}
}


