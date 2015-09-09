/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Unicap_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace ntu { namespace cap {

int _kStorageTypeValues[] = {
  StorageType::InMemoryKeyValue,
  StorageType::LSMKeyValue,
  StorageType::OnDiskKeyValue,
  StorageType::InMemoryImage,
  StorageType::InMemoryMatrix
};
const char* _kStorageTypeNames[] = {
  "InMemoryKeyValue",
  "LSMKeyValue",
  "OnDiskKeyValue",
  "InMemoryImage",
  "InMemoryMatrix"
};
const std::map<int, const char*> _StorageType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kStorageTypeValues, _kStorageTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kKeyPartitionAlgoValues[] = {
  KeyPartitionAlgo::NoneAlgo,
  KeyPartitionAlgo::HashingPartition,
  KeyPartitionAlgo::RangePartition
};
const char* _kKeyPartitionAlgoNames[] = {
  "NoneAlgo",
  "HashingPartition",
  "RangePartition"
};
const std::map<int, const char*> _KeyPartitionAlgo_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kKeyPartitionAlgoValues, _kKeyPartitionAlgoNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));


KeyPartition::~KeyPartition() throw() {
}


void KeyPartition::__set_partition_algo(const KeyPartitionAlgo::type val) {
  this->partition_algo = val;
}

void KeyPartition::__set_key_to_shard(const std::map<int64_t, int64_t> & val) {
  this->key_to_shard = val;
__isset.key_to_shard = true;
}

const char* KeyPartition::ascii_fingerprint = "652978FE52A8D7F6DACE48CF7F5C13D0";
const uint8_t KeyPartition::binary_fingerprint[16] = {0x65,0x29,0x78,0xFE,0x52,0xA8,0xD7,0xF6,0xDA,0xCE,0x48,0xCF,0x7F,0x5C,0x13,0xD0};

uint32_t KeyPartition::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_partition_algo = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->partition_algo = (KeyPartitionAlgo::type)ecast0;
          isset_partition_algo = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->key_to_shard.clear();
            uint32_t _size1;
            ::apache::thrift::protocol::TType _ktype2;
            ::apache::thrift::protocol::TType _vtype3;
            xfer += iprot->readMapBegin(_ktype2, _vtype3, _size1);
            uint32_t _i5;
            for (_i5 = 0; _i5 < _size1; ++_i5)
            {
              int64_t _key6;
              xfer += iprot->readI64(_key6);
              int64_t& _val7 = this->key_to_shard[_key6];
              xfer += iprot->readI64(_val7);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.key_to_shard = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_partition_algo)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t KeyPartition::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("KeyPartition");

  xfer += oprot->writeFieldBegin("partition_algo", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->partition_algo);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.key_to_shard) {
    xfer += oprot->writeFieldBegin("key_to_shard", ::apache::thrift::protocol::T_MAP, 2);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I64, ::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->key_to_shard.size()));
      std::map<int64_t, int64_t> ::const_iterator _iter8;
      for (_iter8 = this->key_to_shard.begin(); _iter8 != this->key_to_shard.end(); ++_iter8)
      {
        xfer += oprot->writeI64(_iter8->first);
        xfer += oprot->writeI64(_iter8->second);
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(KeyPartition &a, KeyPartition &b) {
  using ::std::swap;
  swap(a.partition_algo, b.partition_algo);
  swap(a.key_to_shard, b.key_to_shard);
  swap(a.__isset, b.__isset);
}

KeyPartition::KeyPartition(const KeyPartition& other9) {
  partition_algo = other9.partition_algo;
  key_to_shard = other9.key_to_shard;
  __isset = other9.__isset;
}
KeyPartition& KeyPartition::operator=(const KeyPartition& other10) {
  partition_algo = other10.partition_algo;
  key_to_shard = other10.key_to_shard;
  __isset = other10.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const KeyPartition& obj) {
  using apache::thrift::to_string;
  out << "KeyPartition(";
  out << "partition_algo=" << to_string(obj.partition_algo);
  out << ", " << "key_to_shard="; (obj.__isset.key_to_shard ? (out << to_string(obj.key_to_shard)) : (out << "<null>"));
  out << ")";
  return out;
}


TaskTrackerInfo::~TaskTrackerInfo() throw() {
}


void TaskTrackerInfo::__set_host_name(const std::string& val) {
  this->host_name = val;
}

void TaskTrackerInfo::__set_port(const int64_t val) {
  this->port = val;
}

const char* TaskTrackerInfo::ascii_fingerprint = "1CCCF6FC31CFD1D61BBBB1BAF3590620";
const uint8_t TaskTrackerInfo::binary_fingerprint[16] = {0x1C,0xCC,0xF6,0xFC,0x31,0xCF,0xD1,0xD6,0x1B,0xBB,0xB1,0xBA,0xF3,0x59,0x06,0x20};

uint32_t TaskTrackerInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_host_name = false;
  bool isset_port = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->host_name);
          isset_host_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->port);
          isset_port = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_host_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_port)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TaskTrackerInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("TaskTrackerInfo");

  xfer += oprot->writeFieldBegin("host_name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->host_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("port", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->port);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(TaskTrackerInfo &a, TaskTrackerInfo &b) {
  using ::std::swap;
  swap(a.host_name, b.host_name);
  swap(a.port, b.port);
}

TaskTrackerInfo::TaskTrackerInfo(const TaskTrackerInfo& other11) {
  host_name = other11.host_name;
  port = other11.port;
}
TaskTrackerInfo& TaskTrackerInfo::operator=(const TaskTrackerInfo& other12) {
  host_name = other12.host_name;
  port = other12.port;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const TaskTrackerInfo& obj) {
  using apache::thrift::to_string;
  out << "TaskTrackerInfo(";
  out << "host_name=" << to_string(obj.host_name);
  out << ", " << "port=" << to_string(obj.port);
  out << ")";
  return out;
}


TableProperty::~TableProperty() throw() {
}


void TableProperty::__set_table_name(const std::string& val) {
  this->table_name = val;
}

void TableProperty::__set_shard_num(const int64_t val) {
  this->shard_num = val;
}

void TableProperty::__set_shard_location(const std::map<int64_t, int64_t> & val) {
  this->shard_location = val;
}

void TableProperty::__set_node_info(const std::map<int64_t, std::vector<int64_t> > & val) {
  this->node_info = val;
}

void TableProperty::__set_key_partition(const KeyPartition& val) {
  this->key_partition = val;
}

const char* TableProperty::ascii_fingerprint = "80BC59A6952293A425D72E21CBD8CE25";
const uint8_t TableProperty::binary_fingerprint[16] = {0x80,0xBC,0x59,0xA6,0x95,0x22,0x93,0xA4,0x25,0xD7,0x2E,0x21,0xCB,0xD8,0xCE,0x25};

uint32_t TableProperty::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_table_name = false;
  bool isset_shard_num = false;
  bool isset_shard_location = false;
  bool isset_node_info = false;
  bool isset_key_partition = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->table_name);
          isset_table_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->shard_num);
          isset_shard_num = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->shard_location.clear();
            uint32_t _size13;
            ::apache::thrift::protocol::TType _ktype14;
            ::apache::thrift::protocol::TType _vtype15;
            xfer += iprot->readMapBegin(_ktype14, _vtype15, _size13);
            uint32_t _i17;
            for (_i17 = 0; _i17 < _size13; ++_i17)
            {
              int64_t _key18;
              xfer += iprot->readI64(_key18);
              int64_t& _val19 = this->shard_location[_key18];
              xfer += iprot->readI64(_val19);
            }
            xfer += iprot->readMapEnd();
          }
          isset_shard_location = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->node_info.clear();
            uint32_t _size20;
            ::apache::thrift::protocol::TType _ktype21;
            ::apache::thrift::protocol::TType _vtype22;
            xfer += iprot->readMapBegin(_ktype21, _vtype22, _size20);
            uint32_t _i24;
            for (_i24 = 0; _i24 < _size20; ++_i24)
            {
              int64_t _key25;
              xfer += iprot->readI64(_key25);
              std::vector<int64_t> & _val26 = this->node_info[_key25];
              {
                _val26.clear();
                uint32_t _size27;
                ::apache::thrift::protocol::TType _etype30;
                xfer += iprot->readListBegin(_etype30, _size27);
                _val26.resize(_size27);
                uint32_t _i31;
                for (_i31 = 0; _i31 < _size27; ++_i31)
                {
                  xfer += iprot->readI64(_val26[_i31]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          isset_node_info = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->key_partition.read(iprot);
          isset_key_partition = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_table_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_shard_num)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_shard_location)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_node_info)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_key_partition)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TableProperty::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("TableProperty");

  xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->table_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("shard_num", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->shard_num);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("shard_location", ::apache::thrift::protocol::T_MAP, 3);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I64, ::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->shard_location.size()));
    std::map<int64_t, int64_t> ::const_iterator _iter32;
    for (_iter32 = this->shard_location.begin(); _iter32 != this->shard_location.end(); ++_iter32)
    {
      xfer += oprot->writeI64(_iter32->first);
      xfer += oprot->writeI64(_iter32->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("node_info", ::apache::thrift::protocol::T_MAP, 4);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I64, ::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->node_info.size()));
    std::map<int64_t, std::vector<int64_t> > ::const_iterator _iter33;
    for (_iter33 = this->node_info.begin(); _iter33 != this->node_info.end(); ++_iter33)
    {
      xfer += oprot->writeI64(_iter33->first);
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(_iter33->second.size()));
        std::vector<int64_t> ::const_iterator _iter34;
        for (_iter34 = _iter33->second.begin(); _iter34 != _iter33->second.end(); ++_iter34)
        {
          xfer += oprot->writeI64((*_iter34));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("key_partition", ::apache::thrift::protocol::T_STRUCT, 5);
  xfer += this->key_partition.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(TableProperty &a, TableProperty &b) {
  using ::std::swap;
  swap(a.table_name, b.table_name);
  swap(a.shard_num, b.shard_num);
  swap(a.shard_location, b.shard_location);
  swap(a.node_info, b.node_info);
  swap(a.key_partition, b.key_partition);
}

TableProperty::TableProperty(const TableProperty& other35) {
  table_name = other35.table_name;
  shard_num = other35.shard_num;
  shard_location = other35.shard_location;
  node_info = other35.node_info;
  key_partition = other35.key_partition;
}
TableProperty& TableProperty::operator=(const TableProperty& other36) {
  table_name = other36.table_name;
  shard_num = other36.shard_num;
  shard_location = other36.shard_location;
  node_info = other36.node_info;
  key_partition = other36.key_partition;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const TableProperty& obj) {
  using apache::thrift::to_string;
  out << "TableProperty(";
  out << "table_name=" << to_string(obj.table_name);
  out << ", " << "shard_num=" << to_string(obj.shard_num);
  out << ", " << "shard_location=" << to_string(obj.shard_location);
  out << ", " << "node_info=" << to_string(obj.node_info);
  out << ", " << "key_partition=" << to_string(obj.key_partition);
  out << ")";
  return out;
}


ColumnFamilyProperty::~ColumnFamilyProperty() throw() {
}


void ColumnFamilyProperty::__set_cf_name(const std::string& val) {
  this->cf_name = val;
}

void ColumnFamilyProperty::__set_storage_type(const StorageType::type val) {
  this->storage_type = val;
}

const char* ColumnFamilyProperty::ascii_fingerprint = "D6FD826D949221396F4FFC3ECCD3D192";
const uint8_t ColumnFamilyProperty::binary_fingerprint[16] = {0xD6,0xFD,0x82,0x6D,0x94,0x92,0x21,0x39,0x6F,0x4F,0xFC,0x3E,0xCC,0xD3,0xD1,0x92};

uint32_t ColumnFamilyProperty::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_cf_name = false;
  bool isset_storage_type = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->cf_name);
          isset_cf_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast37;
          xfer += iprot->readI32(ecast37);
          this->storage_type = (StorageType::type)ecast37;
          isset_storage_type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_cf_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_storage_type)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t ColumnFamilyProperty::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("ColumnFamilyProperty");

  xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->cf_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("storage_type", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->storage_type);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(ColumnFamilyProperty &a, ColumnFamilyProperty &b) {
  using ::std::swap;
  swap(a.cf_name, b.cf_name);
  swap(a.storage_type, b.storage_type);
}

ColumnFamilyProperty::ColumnFamilyProperty(const ColumnFamilyProperty& other38) {
  cf_name = other38.cf_name;
  storage_type = other38.storage_type;
}
ColumnFamilyProperty& ColumnFamilyProperty::operator=(const ColumnFamilyProperty& other39) {
  cf_name = other39.cf_name;
  storage_type = other39.storage_type;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const ColumnFamilyProperty& obj) {
  using apache::thrift::to_string;
  out << "ColumnFamilyProperty(";
  out << "cf_name=" << to_string(obj.cf_name);
  out << ", " << "storage_type=" << to_string(obj.storage_type);
  out << ")";
  return out;
}


TaskNode::~TaskNode() throw() {
}


void TaskNode::__set_function_name(const std::string& val) {
  this->function_name = val;
}

void TaskNode::__set_src_table_name(const std::string& val) {
  this->src_table_name = val;
}

void TaskNode::__set_src_shard_id(const int64_t val) {
  this->src_shard_id = val;
}

void TaskNode::__set_src_cf_name(const std::string& val) {
  this->src_cf_name = val;
}

void TaskNode::__set_dst_table_name(const std::string& val) {
  this->dst_table_name = val;
}

void TaskNode::__set_dst_cf_name(const std::string& val) {
  this->dst_cf_name = val;
}

void TaskNode::__set_dst_shard_id(const int64_t val) {
  this->dst_shard_id = val;
__isset.dst_shard_id = true;
}

const char* TaskNode::ascii_fingerprint = "BF7C2E21ACBF1DF13D033E1828E6827C";
const uint8_t TaskNode::binary_fingerprint[16] = {0xBF,0x7C,0x2E,0x21,0xAC,0xBF,0x1D,0xF1,0x3D,0x03,0x3E,0x18,0x28,0xE6,0x82,0x7C};

uint32_t TaskNode::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_function_name = false;
  bool isset_src_table_name = false;
  bool isset_src_shard_id = false;
  bool isset_src_cf_name = false;
  bool isset_dst_table_name = false;
  bool isset_dst_cf_name = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->function_name);
          isset_function_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->src_table_name);
          isset_src_table_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->src_shard_id);
          isset_src_shard_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->src_cf_name);
          isset_src_cf_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->dst_table_name);
          isset_dst_table_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->dst_cf_name);
          isset_dst_cf_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->dst_shard_id);
          this->__isset.dst_shard_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_function_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_src_table_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_src_shard_id)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_src_cf_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_dst_table_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_dst_cf_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TaskNode::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("TaskNode");

  xfer += oprot->writeFieldBegin("function_name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->function_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("src_table_name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->src_table_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("src_shard_id", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->src_shard_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("src_cf_name", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->src_cf_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("dst_table_name", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->dst_table_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("dst_cf_name", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->dst_cf_name);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.dst_shard_id) {
    xfer += oprot->writeFieldBegin("dst_shard_id", ::apache::thrift::protocol::T_I64, 7);
    xfer += oprot->writeI64(this->dst_shard_id);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(TaskNode &a, TaskNode &b) {
  using ::std::swap;
  swap(a.function_name, b.function_name);
  swap(a.src_table_name, b.src_table_name);
  swap(a.src_shard_id, b.src_shard_id);
  swap(a.src_cf_name, b.src_cf_name);
  swap(a.dst_table_name, b.dst_table_name);
  swap(a.dst_cf_name, b.dst_cf_name);
  swap(a.dst_shard_id, b.dst_shard_id);
  swap(a.__isset, b.__isset);
}

TaskNode::TaskNode(const TaskNode& other40) {
  function_name = other40.function_name;
  src_table_name = other40.src_table_name;
  src_shard_id = other40.src_shard_id;
  src_cf_name = other40.src_cf_name;
  dst_table_name = other40.dst_table_name;
  dst_cf_name = other40.dst_cf_name;
  dst_shard_id = other40.dst_shard_id;
  __isset = other40.__isset;
}
TaskNode& TaskNode::operator=(const TaskNode& other41) {
  function_name = other41.function_name;
  src_table_name = other41.src_table_name;
  src_shard_id = other41.src_shard_id;
  src_cf_name = other41.src_cf_name;
  dst_table_name = other41.dst_table_name;
  dst_cf_name = other41.dst_cf_name;
  dst_shard_id = other41.dst_shard_id;
  __isset = other41.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const TaskNode& obj) {
  using apache::thrift::to_string;
  out << "TaskNode(";
  out << "function_name=" << to_string(obj.function_name);
  out << ", " << "src_table_name=" << to_string(obj.src_table_name);
  out << ", " << "src_shard_id=" << to_string(obj.src_shard_id);
  out << ", " << "src_cf_name=" << to_string(obj.src_cf_name);
  out << ", " << "dst_table_name=" << to_string(obj.dst_table_name);
  out << ", " << "dst_cf_name=" << to_string(obj.dst_cf_name);
  out << ", " << "dst_shard_id="; (obj.__isset.dst_shard_id ? (out << to_string(obj.dst_shard_id)) : (out << "<null>"));
  out << ")";
  return out;
}

}} // namespace
