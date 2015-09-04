// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include <iostream>
#include <chrono>
#include <thread>
#include <glog/logging.h>
#include "./job_tracker_server.h"
#include "../common/table.h"
#include "../common/column_family.h"
#include "../common/storage_info.h"

#define JOBTRACKERNAME "localhost"
#define JOBTRACKERPORT 9000

using namespace  ::ntu::cap;

std::thread start_job_tracker() {

    JobTrackerServer::singleton().set_port(JOBTRACKERPORT);
    JobTrackerServer::singleton().set_thread_num(10);
    auto server_thread = JobTrackerServer::singleton().start();

    while(NodeInfo::singleton()._ready_task_tracker_number
          != NodeInfo::singleton()._task_tracker_number
          || NodeInfo::singleton()._ready_task_tracker_number == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
    JobTrackerServer::singleton().create_task_tracker_client();

    for (auto i : JobTrackerServer::singleton().get_client_task_tracker()){
        std::string re;
        i.second->open_transport();
        i.second->method()->ping(re);
        CHECK_EQ(re, "Pong");
        i.second->close_transport();
    }

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

    for (auto i : JobTrackerServer::singleton().get_client_task_tracker()){
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

    for (auto i : JobTrackerServer::singleton().get_client_task_tracker()){
         i.second->open_transport();
         i.second->method()->create_table(new_table._table_property);
         i.second->close_transport();
     }

    VLOG(0) << "CREATE TABLE " << table_name;
    return 1;
}

int64_t create_table(const std::string& table_name, const Table& base_table) {

    Table new_table(table_name, base_table);

    if (StorageInfo::singleton()._table_info.find(table_name)
            != StorageInfo::singleton()._table_info.end()) {
        LOG(FATAL) << "TABLE ALREADY EXISTS !";
    }

    StorageInfo::singleton()._table_info[table_name] = new_table;

    for (auto i : JobTrackerServer::singleton().get_client_task_tracker()){
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
        if (exist_cf._cf_property.cf_name == cf_name) {
            LOG(FATAL) << "CF ALREADY EXISTS !";
        }
    }

    StorageInfo::singleton()._cf_info[table_name]
                           .push_back(new_cf);

    for (auto i : JobTrackerServer::singleton().get_client_task_tracker()){
           i.second->open_transport();
           i.second->method()->create_cf(table_name, new_cf._cf_property);
           i.second->close_transport();
       }

    VLOG(0) << "CREATE CF " << cf_name << " FOR TABLE " << table_name;
    return 1;
}

int main(int argc, char **argv) {
  //google::InitGoogleLogging(argv[0]);

  std::thread server_side_thread;
  server_side_thread = start_job_tracker();

  create_table("a", 100);
  create_cf("a", "a", StorageType::CommonKeyValue);

  server_side_thread.join();
  return 0;
}
