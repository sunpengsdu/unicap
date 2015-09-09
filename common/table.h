/*
 * table.h
 *
 *  Created on: 3 Sep 2015
 *      Author: sunshine
 */

#ifndef NTU_CAP_UNICAP_COMMON_TABLE_H_
#define NTU_CAP_UNICAP_COMMON_TABLE_H_

#include <stdint.h>
#include <map>
#include <string>
#include "../gen/JobTracker.h"
#include "../gen/TaskTracker.h"
#include "./node_info.h"

namespace ntu {
namespace cap {

class Table {
public:

    Table() {
    }

    Table(const std::string& table_name, const Table &base_table) {
        _table_property = base_table._table_property;
        _table_property.table_name = table_name;
    }

    Table(const TableProperty& table_property) {
        _table_property = table_property;
    }

    Table(const std::string& table_name, const int64_t shard_num) {
        _table_property.table_name = table_name;
        _table_property.shard_num  = shard_num;
        _table_property.key_partition.__set_partition_algo(KeyPartitionAlgo::HashingPartition);
    }

    Table(const std::string& table_name, const int64_t shard_num, const KeyPartition partition) {
        _table_property.table_name    = table_name;
        _table_property.shard_num     = shard_num;
        _table_property.key_partition = partition;
    }

    int64_t set_table_name(const std::string& table_name) {
        _table_property.table_name = table_name;
        return 1;
    }

    int64_t set_shard_num(const int64_t shard_num) {
        _table_property.shard_num = shard_num;
        return 1;
    }

    int64_t allocate_shard() {
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

    TableProperty _table_property;
//   std::string _table_name;
//   int64_t     _shard_num;
//   std::map<int64_t, int64_t> _shard_location;
//   std::map<int64_t, std::vector<int64_t>> _node_info;
//   KeyPartition _partition;
};

}
}

#endif /* UNICAP_COMMON_TABLE_H_ */
