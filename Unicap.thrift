namespace cpp ntu.cap

enum StorageType {
CommonKeyValue = 1,
}

enum KeyPartitionAlgo {
HashingPartition = 1,
RangePartition   = 2,
}

struct KeyPartition {
1:  required KeyPartitionAlgo partition_algo,
2:  optional map<i64, i64>    key_to_shard,
}

struct TaskTrackerInfo {
1:  required string host_name,
2:  required i64    port,
}

struct TableProperty {
1:  required string              table_name,
2:  required i64                 shard_num,
3:  required map<i64, i64>       shard_location,
4:  required map<i64, list<i64>> node_info,
5:  required KeyPartition        key_partition,
}

struct ColumnFamilyProperty {
1:  required string      cf_name,
2:  required StorageType storage_type,
}

service JobTracker {
    i64 register_task_tracker(1:i64 node_id, 2:string node_name, 3:i64 storage_weight),
    map<i64, TaskTrackerInfo> get_all_task_tracker_info()
}

service TaskTracker {
    string ping(),
    i64 create_table(1:TableProperty table_property),
    i64 create_cf(1:string table_name, 2:ColumnFamilyProperty cf_property)
}
