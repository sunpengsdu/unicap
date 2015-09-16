/*
 * task_tracker_handler.cpp
 *
 *  Created on: 9 Sep 2015
 *      Author: sunshine
 */

#include "./task_tracker_handler.h"

namespace ntu {
namespace cap {


TaskTrackerHandler::TaskTrackerHandler() {
    // Your initialization goes here
}

void TaskTrackerHandler::ping(std::string& _return) {
    _return = "Pong";
}

int64_t TaskTrackerHandler::check_table(const std::string& table_name,
                                        const int64_t shard_id,
                                        const std::string& cf_name) {
    if (StorageInfo::singleton()._cf_ptr.find(table_name)
            == StorageInfo::singleton()._cf_ptr.end() ) {
        LOG(FATAL) << "CANNOT FIND TABLE " << table_name;
    }

    if (StorageInfo::singleton()._cf_ptr[table_name].find(shard_id)
            == StorageInfo::singleton()._cf_ptr[table_name].end() ) {
        LOG(FATAL) << "CANNOT FIND SHARD ID " << shard_id;
    }

    if (StorageInfo::singleton()._cf_ptr[table_name][shard_id].find(cf_name)
            == StorageInfo::singleton()._cf_ptr[table_name][shard_id].end() ) {
        LOG(FATAL) << "CANNOT FIND SHARD CF " << cf_name;
    }

    return 1;
}

int64_t TaskTrackerHandler::create_table(const TableProperty& table_property) {
    // Your implementation goes here
    Table new_table(table_property);
    StorageInfo::singleton()._table_info[table_property.table_name] = new_table;

    DLOG(INFO) << NodeInfo::singleton()._node_id
               << "("
               << NodeInfo::singleton()._host_name
               << ":"
               << NodeInfo::singleton()._port
               << ")->"
               << "CREATE TABLE "
               << new_table._table_property.table_name;
    return 1;
}

int64_t TaskTrackerHandler::create_cf(const std::string& table_name,
                                      const ColumnFamilyProperty& cf_property) {
    // Your implementation goes here
    if (StorageInfo::singleton()._table_info.find(table_name)
            == StorageInfo::singleton()._table_info.end()) {
        LOG(FATAL) << "CANNOT CREATE CF FOR UNEXIST TABLE " << table_name;
    }

    StorageInfo::singleton()._cf_info[table_name][cf_property.cf_name] = cf_property;

    int64_t node_id = NodeInfo::singleton()._node_id;

    switch (cf_property.storage_type) {
    case StorageType::type::InMemoryKeyValue: {
        //table_name -> shard_id -> cf_name -> ptr
        for (int64_t i : StorageInfo::singleton()._table_info[table_name].
                _table_property.node_info[node_id]) {
            StorageInfo::singleton()._cf_ptr[table_name][i][cf_property.cf_name]
                = std::make_shared<InMemoryKeyValue>(table_name, i, cf_property.cf_name);
        }
        break;
    }

    case StorageType::type::LSMKeyValue: {
        //table_name -> shard_id -> cf_name -> ptr
        for (int64_t i : StorageInfo::singleton()._table_info[table_name].
                _table_property.node_info[node_id]) {
            StorageInfo::singleton()._cf_ptr[table_name][i][cf_property.cf_name]
                = std::make_shared<LSMKeyValue>(table_name, i, cf_property.cf_name);
        }
        break;
    }

    default:
        break;
    }

    DLOG(INFO) << NodeInfo::singleton()._node_id
               << "("
               << NodeInfo::singleton()._host_name
               << ":"
               << NodeInfo::singleton()._port
               << ")->"
               << "CREATE CF "
               << table_name
               << " # "
               << cf_property.cf_name;
    return 1;
}

int64_t TaskTrackerHandler::vector_put(const std::string& table_name,
                                       const int64_t shard_id,
                                       const std::string& cf_name,
                                       const std::vector<std::string> & row_key,
                                       const std::vector<std::string> & column_key,
                                       const std::vector<std::string> & value) {
    // Your implementation goes here

    check_table(table_name, shard_id, cf_name);
    StorageInfo::singleton()._cf_ptr[table_name][shard_id][cf_name] ->
            vector_put(row_key, column_key, value);

    return 1;
}

int64_t TaskTrackerHandler::timely_vector_put(const std::string& table_name,
        const int64_t shard_id,
        const std::string& cf_name,
        const std::vector<std::string> & row_key,
        const std::vector<std::string> & column_key,
        const int64_t time_stampe,
        const std::vector<std::string> & value) {
    // Your implementation goes here
    check_table(table_name, shard_id, cf_name);
    StorageInfo::singleton()._cf_ptr[table_name][shard_id][cf_name] ->
            timely_vector_put(row_key, column_key, time_stampe, value);
    return 1;
}

void TaskTrackerHandler::vector_get(std::vector<std::string> & _return,
                                    const std::string& table_name,
                                    const int64_t shard_id,
                                    const std::string& cf_name,
                                    const std::vector<std::string> & row_key,
                                    const std::vector<std::string> & column_key) {
    // Your implementation goes here
    check_table(table_name, shard_id, cf_name);
    _return.clear();
    StorageInfo::singleton()._cf_ptr[table_name][shard_id][cf_name] ->
            vector_get(row_key, column_key, _return);
}

void TaskTrackerHandler::scan_all(std::vector<std::vector<std::string> > & _return,
                                  const std::string& table_name,
                                  const int64_t shard_id,
                                  const std::string& cf_name) {
    // Your implementation goes here
    check_table(table_name, shard_id, cf_name);
    _return.clear();
    StorageInfo::singleton()._cf_ptr[table_name][shard_id][cf_name] ->
            scan_all(_return);
}

void TaskTrackerHandler::scan_by_time(std::vector<std::vector<std::string> > & _return,
                                      const std::string& table_name,
                                      const int64_t shard_id,
                                      const std::string& cf_name,
                                      const int64_t time_stamp) {
    // Your implementation goes here
    check_table(table_name, shard_id, cf_name);
    _return.clear();
    StorageInfo::singleton()._cf_ptr[table_name][shard_id][cf_name] ->
            scan_by_time(time_stamp, _return);
}

}
}


