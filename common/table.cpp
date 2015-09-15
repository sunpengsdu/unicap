/*
 * table.cpp
 *
 *  Created on: 15 Sep 2015
 *      Author: sunshine
 */
#include "table.h"
namespace ntu {
namespace cap {

Table::Table() {
}

Table::Table(const std::string& table_name, const Table &base_table) {
    _table_property = base_table._table_property;
    _table_property.table_name = table_name;
}

Table::Table(const TableProperty& table_property) {
    _table_property = table_property;
}

Table::Table(const std::string& table_name, const int64_t shard_num) {
    _table_property.table_name = table_name;
    _table_property.shard_num  = shard_num;
    _table_property.key_partition.__set_partition_algo(KeyPartitionAlgo::HashingPartition);
}

Table::Table(const std::string& table_name, const int64_t shard_num, const KeyPartition partition) {
    _table_property.table_name    = table_name;
    _table_property.shard_num     = shard_num;
    _table_property.key_partition = partition;
}

int64_t Table::set_table_name(const std::string& table_name) {
    _table_property.table_name = table_name;
    return 1;
}

int64_t Table::set_shard_num(const int64_t shard_num) {
    _table_property.shard_num = shard_num;
    return 1;
}

int64_t Table::allocate_shard() {
    /*
    int64_t pool_size = NodeInfo::singleton()._storage_weight_pool.size();
    int64_t location;
    for (int i = 0; i < _shard_num; ++i) {
       location = rand() % pool_size;
       _shard_location[i] = location;
       _node_info[location].push_back(i);
    }
    */
    int64_t pool_size = NodeInfo::singleton()._task_tracker_number;
    int64_t rand_num = rand() % pool_size;
    int64_t location = 0;
    for (int i = 0; i < _table_property.shard_num; ++i) {
       location = (i + rand_num) % pool_size;
       _table_property.shard_location[i] = location;
       _table_property.node_info[location].push_back(i);
    }
    return 1;
}

}
}



