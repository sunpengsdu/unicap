namespace cpp ntu.cap

enum KeyPartitionAlgo {
Hashing = 1,
Range   = 2,
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
1:  required string         table_name,
2:  required string         table_type,
3:  required i64            shard_num,
4:  required list<i64>      shard_id_in_charge,
5:  required map<i64, i64>  all_shard_location,
6:  required KeyPartition   key_partition,
}

service JobTracker {
    i64 register_task_tracker(1:i64 node_id, 2:string node_name, 3:i64 storage_weight),
    map<i64, TaskTrackerInfo> get_all_task_tracker_info()
}

service TaskTracker {
    i64 create_table(1:TableProperty table_property)
}
