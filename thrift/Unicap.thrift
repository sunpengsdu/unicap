namespace cpp ntu.cap

enum StorageType {
InMemoryKeyValue = 1,
LSMKeyValue = 2,
OnDiskKeyValue = 3,
InMemoryImage = 4,
InMemoryMatrix = 5,
HdfsKeyValue = 6,
}

enum KeyPartitionAlgo {
NoneAlgo         = 1,
HashingPartition = 2,
RangePartition   = 3,
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

struct TaskNode {
1:  required bool   status,
2:  optional i64    stage_id,
3:  optional i64    task_id,
4:  optional string function_name,
5:  optional string src_table_name,
6:  optional i64    src_shard_id,
7:  optional string src_cf_name,
8:  optional string dst_table_name,
9:  optional string dst_cf_name,
10:  optional i64    dst_shard_id,
}

service JobTracker {
    i64 register_task_tracker(1:i64 node_id, 2:string node_name, 3:i64 storage_weight),
    map<i64, TaskTrackerInfo> get_all_task_tracker_info(),
    TaskNode fetch_cpu_task(1:i64 task_tracker_id)
    TaskNode fetch_gpu_task(1:i64 task_tracker_id)
    i64 complete_cpu_task(1:i64 stage_id, 2:i64 task_id)
    i64 complete_gpu_task(1:i64 stage_id, 2:i64 task_id)
}

service TaskTracker {
    string ping(),
    i64 create_table(1:TableProperty table_property),
    i64 create_cf(1:string table_name, 2:ColumnFamilyProperty cf_property),
    i64 vector_put(1:string table_name, 2:i64 shard_id, 3:string cf_name, 4:list<string> row_key, 5:list<string> column_key, 6:list<string> value),
    i64 timely_vector_put(1:string table_name, 2:i64 shard_id, 3:string cf_name, 4:list<string> row_key, 5:list<string> column_key, 6:i64 time_stampe, 7:list<string> value),
    list<string> vector_get(1:string table_name, 2:i64 shard_id, 3:string cf_name, 4:list<string> row_key, 5:list<string> column_key),
    list<list<string>> scan_all(1:string table_name, 2:i64 shard_id, 3:string cf_name),
    list<list<string>> scan_by_time(1:string table_name, 2:i64 shard_id, 3:string cf_name, 4:i64 time_stamp)
}
