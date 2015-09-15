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

    Table();

    Table(const std::string& table_name, const Table &base_table);

    Table(const TableProperty& table_property);

    Table(const std::string& table_name, const int64_t shard_num);

    Table(const std::string& table_name, const int64_t shard_num, const KeyPartition partition);

    int64_t set_table_name(const std::string& table_name);

    int64_t set_shard_num(const int64_t shard_num);

    int64_t allocate_shard();

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
