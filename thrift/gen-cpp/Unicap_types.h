/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Unicap_TYPES_H
#define Unicap_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace ntu {
namespace cap {

struct StorageType {
    enum type {
        InMemoryKeyValue = 1,
        LSMKeyValue = 2,
        OnDiskKeyValue = 3,
        InMemoryImage = 4,
        InMemoryMatrix = 5,
        HdfsKeyValue = 6
    };
};

extern const std::map<int, const char*> _StorageType_VALUES_TO_NAMES;

struct KeyPartitionAlgo {
    enum type {
        NoneAlgo = 1,
        HashingPartition = 2,
        RangePartition = 3
    };
};

extern const std::map<int, const char*> _KeyPartitionAlgo_VALUES_TO_NAMES;

class KeyPartition;

class TaskTrackerInfo;

class TableProperty;

class ColumnFamilyProperty;

class TaskNode;

typedef struct _KeyPartition__isset {
    _KeyPartition__isset() : key_to_shard(false) {}
    bool key_to_shard :1;
} _KeyPartition__isset;

class KeyPartition {
public:

    static const char* ascii_fingerprint; // = "652978FE52A8D7F6DACE48CF7F5C13D0";
    static const uint8_t binary_fingerprint[16]; // = {0x65,0x29,0x78,0xFE,0x52,0xA8,0xD7,0xF6,0xDA,0xCE,0x48,0xCF,0x7F,0x5C,0x13,0xD0};

    KeyPartition(const KeyPartition&);
    KeyPartition& operator=(const KeyPartition&);
    KeyPartition() : partition_algo((KeyPartitionAlgo::type)0) {
    }

    virtual ~KeyPartition() throw();
    KeyPartitionAlgo::type partition_algo;
    std::map<int64_t, int64_t>  key_to_shard;

    _KeyPartition__isset __isset;

    void __set_partition_algo(const KeyPartitionAlgo::type val);

    void __set_key_to_shard(const std::map<int64_t, int64_t> & val);

    bool operator == (const KeyPartition & rhs) const {
        if (!(partition_algo == rhs.partition_algo))
            return false;
        if (__isset.key_to_shard != rhs.__isset.key_to_shard)
            return false;
        else if (__isset.key_to_shard && !(key_to_shard == rhs.key_to_shard))
            return false;
        return true;
    }
    bool operator != (const KeyPartition &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const KeyPartition & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const KeyPartition& obj);
};

void swap(KeyPartition &a, KeyPartition &b);


class TaskTrackerInfo {
public:

    static const char* ascii_fingerprint; // = "1CCCF6FC31CFD1D61BBBB1BAF3590620";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xCC,0xF6,0xFC,0x31,0xCF,0xD1,0xD6,0x1B,0xBB,0xB1,0xBA,0xF3,0x59,0x06,0x20};

    TaskTrackerInfo(const TaskTrackerInfo&);
    TaskTrackerInfo& operator=(const TaskTrackerInfo&);
    TaskTrackerInfo() : host_name(), port(0) {
    }

    virtual ~TaskTrackerInfo() throw();
    std::string host_name;
    int64_t port;

    void __set_host_name(const std::string& val);

    void __set_port(const int64_t val);

    bool operator == (const TaskTrackerInfo & rhs) const {
        if (!(host_name == rhs.host_name))
            return false;
        if (!(port == rhs.port))
            return false;
        return true;
    }
    bool operator != (const TaskTrackerInfo &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTrackerInfo & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTrackerInfo& obj);
};

void swap(TaskTrackerInfo &a, TaskTrackerInfo &b);


class TableProperty {
public:

    static const char* ascii_fingerprint; // = "80BC59A6952293A425D72E21CBD8CE25";
    static const uint8_t binary_fingerprint[16]; // = {0x80,0xBC,0x59,0xA6,0x95,0x22,0x93,0xA4,0x25,0xD7,0x2E,0x21,0xCB,0xD8,0xCE,0x25};

    TableProperty(const TableProperty&);
    TableProperty& operator=(const TableProperty&);
    TableProperty() : table_name(), shard_num(0) {
    }

    virtual ~TableProperty() throw();
    std::string table_name;
    int64_t shard_num;
    std::map<int64_t, int64_t>  shard_location;
    std::map<int64_t, std::vector<int64_t> >  node_info;
    KeyPartition key_partition;

    void __set_table_name(const std::string& val);

    void __set_shard_num(const int64_t val);

    void __set_shard_location(const std::map<int64_t, int64_t> & val);

    void __set_node_info(const std::map<int64_t, std::vector<int64_t> > & val);

    void __set_key_partition(const KeyPartition& val);

    bool operator == (const TableProperty & rhs) const {
        if (!(table_name == rhs.table_name))
            return false;
        if (!(shard_num == rhs.shard_num))
            return false;
        if (!(shard_location == rhs.shard_location))
            return false;
        if (!(node_info == rhs.node_info))
            return false;
        if (!(key_partition == rhs.key_partition))
            return false;
        return true;
    }
    bool operator != (const TableProperty &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TableProperty & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TableProperty& obj);
};

void swap(TableProperty &a, TableProperty &b);


class ColumnFamilyProperty {
public:

    static const char* ascii_fingerprint; // = "D6FD826D949221396F4FFC3ECCD3D192";
    static const uint8_t binary_fingerprint[16]; // = {0xD6,0xFD,0x82,0x6D,0x94,0x92,0x21,0x39,0x6F,0x4F,0xFC,0x3E,0xCC,0xD3,0xD1,0x92};

    ColumnFamilyProperty(const ColumnFamilyProperty&);
    ColumnFamilyProperty& operator=(const ColumnFamilyProperty&);
    ColumnFamilyProperty() : cf_name(), storage_type((StorageType::type)0) {
    }

    virtual ~ColumnFamilyProperty() throw();
    std::string cf_name;
    StorageType::type storage_type;

    void __set_cf_name(const std::string& val);

    void __set_storage_type(const StorageType::type val);

    bool operator == (const ColumnFamilyProperty & rhs) const {
        if (!(cf_name == rhs.cf_name))
            return false;
        if (!(storage_type == rhs.storage_type))
            return false;
        return true;
    }
    bool operator != (const ColumnFamilyProperty &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const ColumnFamilyProperty & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const ColumnFamilyProperty& obj);
};

void swap(ColumnFamilyProperty &a, ColumnFamilyProperty &b);

typedef struct _TaskNode__isset {
    _TaskNode__isset() : stage_id(false), task_id(false), function_name(false), src_table_name(false), src_shard_id(false), src_cf_name(false), dst_table_name(false), dst_cf_name(false), dst_shard_id(false) {}
    bool stage_id :1;
    bool task_id :1;
    bool function_name :1;
    bool src_table_name :1;
    bool src_shard_id :1;
    bool src_cf_name :1;
    bool dst_table_name :1;
    bool dst_cf_name :1;
    bool dst_shard_id :1;
} _TaskNode__isset;

class TaskNode {
public:

    static const char* ascii_fingerprint; // = "798F338BF6386D059FAE60C04F1048BF";
    static const uint8_t binary_fingerprint[16]; // = {0x79,0x8F,0x33,0x8B,0xF6,0x38,0x6D,0x05,0x9F,0xAE,0x60,0xC0,0x4F,0x10,0x48,0xBF};

    TaskNode(const TaskNode&);
    TaskNode& operator=(const TaskNode&);
    TaskNode() : status(0), stage_id(0), task_id(0), function_name(), src_table_name(), src_shard_id(0), src_cf_name(), dst_table_name(), dst_cf_name(), dst_shard_id(0) {
    }

    virtual ~TaskNode() throw();
    bool status;
    int64_t stage_id;
    int64_t task_id;
    std::string function_name;
    std::string src_table_name;
    int64_t src_shard_id;
    std::string src_cf_name;
    std::string dst_table_name;
    std::string dst_cf_name;
    int64_t dst_shard_id;

    _TaskNode__isset __isset;

    void __set_status(const bool val);

    void __set_stage_id(const int64_t val);

    void __set_task_id(const int64_t val);

    void __set_function_name(const std::string& val);

    void __set_src_table_name(const std::string& val);

    void __set_src_shard_id(const int64_t val);

    void __set_src_cf_name(const std::string& val);

    void __set_dst_table_name(const std::string& val);

    void __set_dst_cf_name(const std::string& val);

    void __set_dst_shard_id(const int64_t val);

    bool operator == (const TaskNode & rhs) const {
        if (!(status == rhs.status))
            return false;
        if (__isset.stage_id != rhs.__isset.stage_id)
            return false;
        else if (__isset.stage_id && !(stage_id == rhs.stage_id))
            return false;
        if (__isset.task_id != rhs.__isset.task_id)
            return false;
        else if (__isset.task_id && !(task_id == rhs.task_id))
            return false;
        if (__isset.function_name != rhs.__isset.function_name)
            return false;
        else if (__isset.function_name && !(function_name == rhs.function_name))
            return false;
        if (__isset.src_table_name != rhs.__isset.src_table_name)
            return false;
        else if (__isset.src_table_name && !(src_table_name == rhs.src_table_name))
            return false;
        if (__isset.src_shard_id != rhs.__isset.src_shard_id)
            return false;
        else if (__isset.src_shard_id && !(src_shard_id == rhs.src_shard_id))
            return false;
        if (__isset.src_cf_name != rhs.__isset.src_cf_name)
            return false;
        else if (__isset.src_cf_name && !(src_cf_name == rhs.src_cf_name))
            return false;
        if (__isset.dst_table_name != rhs.__isset.dst_table_name)
            return false;
        else if (__isset.dst_table_name && !(dst_table_name == rhs.dst_table_name))
            return false;
        if (__isset.dst_cf_name != rhs.__isset.dst_cf_name)
            return false;
        else if (__isset.dst_cf_name && !(dst_cf_name == rhs.dst_cf_name))
            return false;
        if (__isset.dst_shard_id != rhs.__isset.dst_shard_id)
            return false;
        else if (__isset.dst_shard_id && !(dst_shard_id == rhs.dst_shard_id))
            return false;
        return true;
    }
    bool operator != (const TaskNode &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskNode & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskNode& obj);
};

void swap(TaskNode &a, TaskNode &b);

}
} // namespace

#endif