// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.
#ifndef NTU_CAP_UNICAP_TASK_TRACKER_TASK_TRACKER_HANDLER_H
#define NTU_CAP_UNICAP_TASK_TRACKER_TASK_TRACKER_HANDLER_H

#include "../gen/TaskTracker.h"
#include "../common/node_info.h"
#include "../common/table.h"
#include "../common/column_family.h"
#include "../common/storage_info.h"

namespace ntu {
namespace cap {

class TaskTrackerHandler : virtual public TaskTrackerIf {
public:
  TaskTrackerHandler() {
    // Your initialization goes here
  }

  void ping(std::string& _return) {
      _return = "Pong";
   }

  int64_t create_table(const TableProperty& table_property) {
    // Your implementation goes here
    Table new_table(table_property);
    StorageInfo::singleton()._table_info[table_property.table_name] = new_table;

    VLOG(0) << NodeInfo::singleton()._node_id
            << "("
            << NodeInfo::singleton()._host_name
            << ":"
            << NodeInfo::singleton()._port
            << ")->"
            << "CREATE TABLE "
            << new_table._table_property.table_name;
    return 1;
  }

  int64_t create_cf(const std::string& table_name, const ColumnFamilyProperty& cf_property) {
    // Your implementation goes here
    ColumnFamily new_cf(cf_property);
    StorageInfo::singleton()._cf_info[table_name][cf_property.cf_name] = cf_property;

    VLOG(0) << NodeInfo::singleton()._node_id
            << "("
            << NodeInfo::singleton()._host_name
            << ":"
            << NodeInfo::singleton()._port
            << ")->"
            << "CREATE CF "
            << table_name
            << " # "
            << new_cf._cf_property.cf_name;
    return 1;
  }

private:
};

} //end namespace ntu
} //end namespace cap
#endif

//std::map<int64_t, TaskTrackerInfo> & _return
//boost::shared_ptr<UnicapClient<JobTrackerClient>> _client;
