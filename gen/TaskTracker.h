/*
 *Copyright 2015 NTU (http://www.ntu.edu.sg/)
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
*/
#ifndef TaskTracker_H
#define TaskTracker_H

#include <thrift/TDispatchProcessor.h>
#include "Unicap_types.h"

namespace ntu {
namespace cap {

class TaskTrackerIf {
public:
    virtual ~TaskTrackerIf() {}
    virtual void ping(std::string& _return) = 0;
    virtual int64_t create_table(const TableProperty& table_property) = 0;
    virtual int64_t create_cf(const std::string& table_name, const ColumnFamilyProperty& cf_property) = 0;
    virtual int64_t vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const std::vector<std::string> & value) = 0;
    virtual int64_t timely_vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const int64_t time_stampe, const std::vector<std::string> & value) = 0;
    virtual void vector_get(std::vector<std::string> & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key) = 0;
    virtual void scan_all(std::vector<std::vector<std::string> > & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name) = 0;
    virtual void scan_by_time(std::vector<std::vector<std::string> > & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const int64_t time_stamp) = 0;
};

class TaskTrackerIfFactory {
public:
    typedef TaskTrackerIf Handler;

    virtual ~TaskTrackerIfFactory() {}

    virtual TaskTrackerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
    virtual void releaseHandler(TaskTrackerIf* /* handler */) = 0;
};

class TaskTrackerIfSingletonFactory : virtual public TaskTrackerIfFactory {
public:
    TaskTrackerIfSingletonFactory(const boost::shared_ptr<TaskTrackerIf>& iface) : iface_(iface) {}
    virtual ~TaskTrackerIfSingletonFactory() {}

    virtual TaskTrackerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
        return iface_.get();
    }
    virtual void releaseHandler(TaskTrackerIf* /* handler */) {}

protected:
    boost::shared_ptr<TaskTrackerIf> iface_;
};

class TaskTrackerNull : virtual public TaskTrackerIf {
public:
    virtual ~TaskTrackerNull() {}
    void ping(std::string& /* _return */) {
        return;
    }
    int64_t create_table(const TableProperty& /* table_property */) {
        int64_t _return = 0;
        return _return;
    }
    int64_t create_cf(const std::string& /* table_name */, const ColumnFamilyProperty& /* cf_property */) {
        int64_t _return = 0;
        return _return;
    }
    int64_t vector_put(const std::string& /* table_name */, const int64_t /* shard_id */, const std::string& /* cf_name */, const std::vector<std::string> & /* row_key */, const std::vector<std::string> & /* column_key */, const std::vector<std::string> & /* value */) {
        int64_t _return = 0;
        return _return;
    }
    int64_t timely_vector_put(const std::string& /* table_name */, const int64_t /* shard_id */, const std::string& /* cf_name */, const std::vector<std::string> & /* row_key */, const std::vector<std::string> & /* column_key */, const int64_t /* time_stampe */, const std::vector<std::string> & /* value */) {
        int64_t _return = 0;
        return _return;
    }
    void vector_get(std::vector<std::string> & /* _return */, const std::string& /* table_name */, const int64_t /* shard_id */, const std::string& /* cf_name */, const std::vector<std::string> & /* row_key */, const std::vector<std::string> & /* column_key */) {
        return;
    }
    void scan_all(std::vector<std::vector<std::string> > & /* _return */, const std::string& /* table_name */, const int64_t /* shard_id */, const std::string& /* cf_name */) {
        return;
    }
    void scan_by_time(std::vector<std::vector<std::string> > & /* _return */, const std::string& /* table_name */, const int64_t /* shard_id */, const std::string& /* cf_name */, const int64_t /* time_stamp */) {
        return;
    }
};


class TaskTracker_ping_args {
public:

    static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
    static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

    TaskTracker_ping_args(const TaskTracker_ping_args&);
    TaskTracker_ping_args& operator=(const TaskTracker_ping_args&);
    TaskTracker_ping_args() {
    }

    virtual ~TaskTracker_ping_args() throw();

    bool operator == (const TaskTracker_ping_args & /* rhs */) const {
        return true;
    }
    bool operator != (const TaskTracker_ping_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_ping_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_ping_args& obj);
};


class TaskTracker_ping_pargs {
public:

    static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
    static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


    virtual ~TaskTracker_ping_pargs() throw();

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_ping_pargs& obj);
};

typedef struct _TaskTracker_ping_result__isset {
    _TaskTracker_ping_result__isset() : success(false) {}
    bool success :1;
} _TaskTracker_ping_result__isset;

class TaskTracker_ping_result {
public:

    static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
    static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};

    TaskTracker_ping_result(const TaskTracker_ping_result&);
    TaskTracker_ping_result& operator=(const TaskTracker_ping_result&);
    TaskTracker_ping_result() : success() {
    }

    virtual ~TaskTracker_ping_result() throw();
    std::string success;

    _TaskTracker_ping_result__isset __isset;

    void __set_success(const std::string& val);

    bool operator == (const TaskTracker_ping_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_ping_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_ping_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_ping_result& obj);
};

typedef struct _TaskTracker_ping_presult__isset {
    _TaskTracker_ping_presult__isset() : success(false) {}
    bool success :1;
} _TaskTracker_ping_presult__isset;

class TaskTracker_ping_presult {
public:

    static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
    static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};


    virtual ~TaskTracker_ping_presult() throw();
    std::string* success;

    _TaskTracker_ping_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_ping_presult& obj);
};

typedef struct _TaskTracker_create_table_args__isset {
    _TaskTracker_create_table_args__isset() : table_property(false) {}
    bool table_property :1;
} _TaskTracker_create_table_args__isset;

class TaskTracker_create_table_args {
public:

    static const char* ascii_fingerprint; // = "A994C462A9885EC03D28E5F7CD843CFB";
    static const uint8_t binary_fingerprint[16]; // = {0xA9,0x94,0xC4,0x62,0xA9,0x88,0x5E,0xC0,0x3D,0x28,0xE5,0xF7,0xCD,0x84,0x3C,0xFB};

    TaskTracker_create_table_args(const TaskTracker_create_table_args&);
    TaskTracker_create_table_args& operator=(const TaskTracker_create_table_args&);
    TaskTracker_create_table_args() {
    }

    virtual ~TaskTracker_create_table_args() throw();
    TableProperty table_property;

    _TaskTracker_create_table_args__isset __isset;

    void __set_table_property(const TableProperty& val);

    bool operator == (const TaskTracker_create_table_args & rhs) const {
        if (!(table_property == rhs.table_property))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_create_table_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_create_table_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_create_table_args& obj);
};


class TaskTracker_create_table_pargs {
public:

    static const char* ascii_fingerprint; // = "A994C462A9885EC03D28E5F7CD843CFB";
    static const uint8_t binary_fingerprint[16]; // = {0xA9,0x94,0xC4,0x62,0xA9,0x88,0x5E,0xC0,0x3D,0x28,0xE5,0xF7,0xCD,0x84,0x3C,0xFB};


    virtual ~TaskTracker_create_table_pargs() throw();
    const TableProperty* table_property;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_create_table_pargs& obj);
};

typedef struct _TaskTracker_create_table_result__isset {
    _TaskTracker_create_table_result__isset() : success(false) {}
    bool success :1;
} _TaskTracker_create_table_result__isset;

class TaskTracker_create_table_result {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};

    TaskTracker_create_table_result(const TaskTracker_create_table_result&);
    TaskTracker_create_table_result& operator=(const TaskTracker_create_table_result&);
    TaskTracker_create_table_result() : success(0) {
    }

    virtual ~TaskTracker_create_table_result() throw();
    int64_t success;

    _TaskTracker_create_table_result__isset __isset;

    void __set_success(const int64_t val);

    bool operator == (const TaskTracker_create_table_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_create_table_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_create_table_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_create_table_result& obj);
};

typedef struct _TaskTracker_create_table_presult__isset {
    _TaskTracker_create_table_presult__isset() : success(false) {}
    bool success :1;
} _TaskTracker_create_table_presult__isset;

class TaskTracker_create_table_presult {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};


    virtual ~TaskTracker_create_table_presult() throw();
    int64_t* success;

    _TaskTracker_create_table_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_create_table_presult& obj);
};

typedef struct _TaskTracker_create_cf_args__isset {
    _TaskTracker_create_cf_args__isset() : table_name(false), cf_property(false) {}
    bool table_name :1;
    bool cf_property :1;
} _TaskTracker_create_cf_args__isset;

class TaskTracker_create_cf_args {
public:

    static const char* ascii_fingerprint; // = "A495BD300003796402A16D498FD212BC";
    static const uint8_t binary_fingerprint[16]; // = {0xA4,0x95,0xBD,0x30,0x00,0x03,0x79,0x64,0x02,0xA1,0x6D,0x49,0x8F,0xD2,0x12,0xBC};

    TaskTracker_create_cf_args(const TaskTracker_create_cf_args&);
    TaskTracker_create_cf_args& operator=(const TaskTracker_create_cf_args&);
    TaskTracker_create_cf_args() : table_name() {
    }

    virtual ~TaskTracker_create_cf_args() throw();
    std::string table_name;
    ColumnFamilyProperty cf_property;

    _TaskTracker_create_cf_args__isset __isset;

    void __set_table_name(const std::string& val);

    void __set_cf_property(const ColumnFamilyProperty& val);

    bool operator == (const TaskTracker_create_cf_args & rhs) const {
        if (!(table_name == rhs.table_name))
            return false;
        if (!(cf_property == rhs.cf_property))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_create_cf_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_create_cf_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_create_cf_args& obj);
};


class TaskTracker_create_cf_pargs {
public:

    static const char* ascii_fingerprint; // = "A495BD300003796402A16D498FD212BC";
    static const uint8_t binary_fingerprint[16]; // = {0xA4,0x95,0xBD,0x30,0x00,0x03,0x79,0x64,0x02,0xA1,0x6D,0x49,0x8F,0xD2,0x12,0xBC};


    virtual ~TaskTracker_create_cf_pargs() throw();
    const std::string* table_name;
    const ColumnFamilyProperty* cf_property;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_create_cf_pargs& obj);
};

typedef struct _TaskTracker_create_cf_result__isset {
    _TaskTracker_create_cf_result__isset() : success(false) {}
    bool success :1;
} _TaskTracker_create_cf_result__isset;

class TaskTracker_create_cf_result {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};

    TaskTracker_create_cf_result(const TaskTracker_create_cf_result&);
    TaskTracker_create_cf_result& operator=(const TaskTracker_create_cf_result&);
    TaskTracker_create_cf_result() : success(0) {
    }

    virtual ~TaskTracker_create_cf_result() throw();
    int64_t success;

    _TaskTracker_create_cf_result__isset __isset;

    void __set_success(const int64_t val);

    bool operator == (const TaskTracker_create_cf_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_create_cf_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_create_cf_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_create_cf_result& obj);
};

typedef struct _TaskTracker_create_cf_presult__isset {
    _TaskTracker_create_cf_presult__isset() : success(false) {}
    bool success :1;
} _TaskTracker_create_cf_presult__isset;

class TaskTracker_create_cf_presult {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};


    virtual ~TaskTracker_create_cf_presult() throw();
    int64_t* success;

    _TaskTracker_create_cf_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_create_cf_presult& obj);
};

typedef struct _TaskTracker_vector_put_args__isset {
    _TaskTracker_vector_put_args__isset() : table_name(false), shard_id(false), cf_name(false), row_key(false), column_key(false), value(false) {}
    bool table_name :1;
    bool shard_id :1;
    bool cf_name :1;
    bool row_key :1;
    bool column_key :1;
    bool value :1;
} _TaskTracker_vector_put_args__isset;

class TaskTracker_vector_put_args {
public:

    static const char* ascii_fingerprint; // = "D2CCF06D29628375E6E017A8A4C833B1";
    static const uint8_t binary_fingerprint[16]; // = {0xD2,0xCC,0xF0,0x6D,0x29,0x62,0x83,0x75,0xE6,0xE0,0x17,0xA8,0xA4,0xC8,0x33,0xB1};

    TaskTracker_vector_put_args(const TaskTracker_vector_put_args&);
    TaskTracker_vector_put_args& operator=(const TaskTracker_vector_put_args&);
    TaskTracker_vector_put_args() : table_name(), shard_id(0), cf_name() {
    }

    virtual ~TaskTracker_vector_put_args() throw();
    std::string table_name;
    int64_t shard_id;
    std::string cf_name;
    std::vector<std::string>  row_key;
    std::vector<std::string>  column_key;
    std::vector<std::string>  value;

    _TaskTracker_vector_put_args__isset __isset;

    void __set_table_name(const std::string& val);

    void __set_shard_id(const int64_t val);

    void __set_cf_name(const std::string& val);

    void __set_row_key(const std::vector<std::string> & val);

    void __set_column_key(const std::vector<std::string> & val);

    void __set_value(const std::vector<std::string> & val);

    bool operator == (const TaskTracker_vector_put_args & rhs) const {
        if (!(table_name == rhs.table_name))
            return false;
        if (!(shard_id == rhs.shard_id))
            return false;
        if (!(cf_name == rhs.cf_name))
            return false;
        if (!(row_key == rhs.row_key))
            return false;
        if (!(column_key == rhs.column_key))
            return false;
        if (!(value == rhs.value))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_vector_put_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_vector_put_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_vector_put_args& obj);
};


class TaskTracker_vector_put_pargs {
public:

    static const char* ascii_fingerprint; // = "D2CCF06D29628375E6E017A8A4C833B1";
    static const uint8_t binary_fingerprint[16]; // = {0xD2,0xCC,0xF0,0x6D,0x29,0x62,0x83,0x75,0xE6,0xE0,0x17,0xA8,0xA4,0xC8,0x33,0xB1};


    virtual ~TaskTracker_vector_put_pargs() throw();
    const std::string* table_name;
    const int64_t* shard_id;
    const std::string* cf_name;
    const std::vector<std::string> * row_key;
    const std::vector<std::string> * column_key;
    const std::vector<std::string> * value;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_vector_put_pargs& obj);
};

typedef struct _TaskTracker_vector_put_result__isset {
    _TaskTracker_vector_put_result__isset() : success(false) {}
    bool success :1;
} _TaskTracker_vector_put_result__isset;

class TaskTracker_vector_put_result {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};

    TaskTracker_vector_put_result(const TaskTracker_vector_put_result&);
    TaskTracker_vector_put_result& operator=(const TaskTracker_vector_put_result&);
    TaskTracker_vector_put_result() : success(0) {
    }

    virtual ~TaskTracker_vector_put_result() throw();
    int64_t success;

    _TaskTracker_vector_put_result__isset __isset;

    void __set_success(const int64_t val);

    bool operator == (const TaskTracker_vector_put_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_vector_put_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_vector_put_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_vector_put_result& obj);
};

typedef struct _TaskTracker_vector_put_presult__isset {
    _TaskTracker_vector_put_presult__isset() : success(false) {}
    bool success :1;
} _TaskTracker_vector_put_presult__isset;

class TaskTracker_vector_put_presult {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};


    virtual ~TaskTracker_vector_put_presult() throw();
    int64_t* success;

    _TaskTracker_vector_put_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_vector_put_presult& obj);
};

typedef struct _TaskTracker_timely_vector_put_args__isset {
    _TaskTracker_timely_vector_put_args__isset() : table_name(false), shard_id(false), cf_name(false), row_key(false), column_key(false), time_stampe(false), value(false) {}
    bool table_name :1;
    bool shard_id :1;
    bool cf_name :1;
    bool row_key :1;
    bool column_key :1;
    bool time_stampe :1;
    bool value :1;
} _TaskTracker_timely_vector_put_args__isset;

class TaskTracker_timely_vector_put_args {
public:

    static const char* ascii_fingerprint; // = "1ED373136B9FB0A435E8DF0F595A35B4";
    static const uint8_t binary_fingerprint[16]; // = {0x1E,0xD3,0x73,0x13,0x6B,0x9F,0xB0,0xA4,0x35,0xE8,0xDF,0x0F,0x59,0x5A,0x35,0xB4};

    TaskTracker_timely_vector_put_args(const TaskTracker_timely_vector_put_args&);
    TaskTracker_timely_vector_put_args& operator=(const TaskTracker_timely_vector_put_args&);
    TaskTracker_timely_vector_put_args() : table_name(), shard_id(0), cf_name(), time_stampe(0) {
    }

    virtual ~TaskTracker_timely_vector_put_args() throw();
    std::string table_name;
    int64_t shard_id;
    std::string cf_name;
    std::vector<std::string>  row_key;
    std::vector<std::string>  column_key;
    int64_t time_stampe;
    std::vector<std::string>  value;

    _TaskTracker_timely_vector_put_args__isset __isset;

    void __set_table_name(const std::string& val);

    void __set_shard_id(const int64_t val);

    void __set_cf_name(const std::string& val);

    void __set_row_key(const std::vector<std::string> & val);

    void __set_column_key(const std::vector<std::string> & val);

    void __set_time_stampe(const int64_t val);

    void __set_value(const std::vector<std::string> & val);

    bool operator == (const TaskTracker_timely_vector_put_args & rhs) const {
        if (!(table_name == rhs.table_name))
            return false;
        if (!(shard_id == rhs.shard_id))
            return false;
        if (!(cf_name == rhs.cf_name))
            return false;
        if (!(row_key == rhs.row_key))
            return false;
        if (!(column_key == rhs.column_key))
            return false;
        if (!(time_stampe == rhs.time_stampe))
            return false;
        if (!(value == rhs.value))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_timely_vector_put_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_timely_vector_put_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_timely_vector_put_args& obj);
};


class TaskTracker_timely_vector_put_pargs {
public:

    static const char* ascii_fingerprint; // = "1ED373136B9FB0A435E8DF0F595A35B4";
    static const uint8_t binary_fingerprint[16]; // = {0x1E,0xD3,0x73,0x13,0x6B,0x9F,0xB0,0xA4,0x35,0xE8,0xDF,0x0F,0x59,0x5A,0x35,0xB4};


    virtual ~TaskTracker_timely_vector_put_pargs() throw();
    const std::string* table_name;
    const int64_t* shard_id;
    const std::string* cf_name;
    const std::vector<std::string> * row_key;
    const std::vector<std::string> * column_key;
    const int64_t* time_stampe;
    const std::vector<std::string> * value;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_timely_vector_put_pargs& obj);
};

typedef struct _TaskTracker_timely_vector_put_result__isset {
    _TaskTracker_timely_vector_put_result__isset() : success(false) {}
    bool success :1;
} _TaskTracker_timely_vector_put_result__isset;

class TaskTracker_timely_vector_put_result {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};

    TaskTracker_timely_vector_put_result(const TaskTracker_timely_vector_put_result&);
    TaskTracker_timely_vector_put_result& operator=(const TaskTracker_timely_vector_put_result&);
    TaskTracker_timely_vector_put_result() : success(0) {
    }

    virtual ~TaskTracker_timely_vector_put_result() throw();
    int64_t success;

    _TaskTracker_timely_vector_put_result__isset __isset;

    void __set_success(const int64_t val);

    bool operator == (const TaskTracker_timely_vector_put_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_timely_vector_put_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_timely_vector_put_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_timely_vector_put_result& obj);
};

typedef struct _TaskTracker_timely_vector_put_presult__isset {
    _TaskTracker_timely_vector_put_presult__isset() : success(false) {}
    bool success :1;
} _TaskTracker_timely_vector_put_presult__isset;

class TaskTracker_timely_vector_put_presult {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};


    virtual ~TaskTracker_timely_vector_put_presult() throw();
    int64_t* success;

    _TaskTracker_timely_vector_put_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_timely_vector_put_presult& obj);
};

typedef struct _TaskTracker_vector_get_args__isset {
    _TaskTracker_vector_get_args__isset() : table_name(false), shard_id(false), cf_name(false), row_key(false), column_key(false) {}
    bool table_name :1;
    bool shard_id :1;
    bool cf_name :1;
    bool row_key :1;
    bool column_key :1;
} _TaskTracker_vector_get_args__isset;

class TaskTracker_vector_get_args {
public:

    static const char* ascii_fingerprint; // = "78A77717508DF6C5304E2FEC8540EE87";
    static const uint8_t binary_fingerprint[16]; // = {0x78,0xA7,0x77,0x17,0x50,0x8D,0xF6,0xC5,0x30,0x4E,0x2F,0xEC,0x85,0x40,0xEE,0x87};

    TaskTracker_vector_get_args(const TaskTracker_vector_get_args&);
    TaskTracker_vector_get_args& operator=(const TaskTracker_vector_get_args&);
    TaskTracker_vector_get_args() : table_name(), shard_id(0), cf_name() {
    }

    virtual ~TaskTracker_vector_get_args() throw();
    std::string table_name;
    int64_t shard_id;
    std::string cf_name;
    std::vector<std::string>  row_key;
    std::vector<std::string>  column_key;

    _TaskTracker_vector_get_args__isset __isset;

    void __set_table_name(const std::string& val);

    void __set_shard_id(const int64_t val);

    void __set_cf_name(const std::string& val);

    void __set_row_key(const std::vector<std::string> & val);

    void __set_column_key(const std::vector<std::string> & val);

    bool operator == (const TaskTracker_vector_get_args & rhs) const {
        if (!(table_name == rhs.table_name))
            return false;
        if (!(shard_id == rhs.shard_id))
            return false;
        if (!(cf_name == rhs.cf_name))
            return false;
        if (!(row_key == rhs.row_key))
            return false;
        if (!(column_key == rhs.column_key))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_vector_get_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_vector_get_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_vector_get_args& obj);
};


class TaskTracker_vector_get_pargs {
public:

    static const char* ascii_fingerprint; // = "78A77717508DF6C5304E2FEC8540EE87";
    static const uint8_t binary_fingerprint[16]; // = {0x78,0xA7,0x77,0x17,0x50,0x8D,0xF6,0xC5,0x30,0x4E,0x2F,0xEC,0x85,0x40,0xEE,0x87};


    virtual ~TaskTracker_vector_get_pargs() throw();
    const std::string* table_name;
    const int64_t* shard_id;
    const std::string* cf_name;
    const std::vector<std::string> * row_key;
    const std::vector<std::string> * column_key;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_vector_get_pargs& obj);
};

typedef struct _TaskTracker_vector_get_result__isset {
    _TaskTracker_vector_get_result__isset() : success(false) {}
    bool success :1;
} _TaskTracker_vector_get_result__isset;

class TaskTracker_vector_get_result {
public:

    static const char* ascii_fingerprint; // = "C844643081B14EA3A81E57199FB2B504";
    static const uint8_t binary_fingerprint[16]; // = {0xC8,0x44,0x64,0x30,0x81,0xB1,0x4E,0xA3,0xA8,0x1E,0x57,0x19,0x9F,0xB2,0xB5,0x04};

    TaskTracker_vector_get_result(const TaskTracker_vector_get_result&);
    TaskTracker_vector_get_result& operator=(const TaskTracker_vector_get_result&);
    TaskTracker_vector_get_result() {
    }

    virtual ~TaskTracker_vector_get_result() throw();
    std::vector<std::string>  success;

    _TaskTracker_vector_get_result__isset __isset;

    void __set_success(const std::vector<std::string> & val);

    bool operator == (const TaskTracker_vector_get_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_vector_get_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_vector_get_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_vector_get_result& obj);
};

typedef struct _TaskTracker_vector_get_presult__isset {
    _TaskTracker_vector_get_presult__isset() : success(false) {}
    bool success :1;
} _TaskTracker_vector_get_presult__isset;

class TaskTracker_vector_get_presult {
public:

    static const char* ascii_fingerprint; // = "C844643081B14EA3A81E57199FB2B504";
    static const uint8_t binary_fingerprint[16]; // = {0xC8,0x44,0x64,0x30,0x81,0xB1,0x4E,0xA3,0xA8,0x1E,0x57,0x19,0x9F,0xB2,0xB5,0x04};


    virtual ~TaskTracker_vector_get_presult() throw();
    std::vector<std::string> * success;

    _TaskTracker_vector_get_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_vector_get_presult& obj);
};

typedef struct _TaskTracker_scan_all_args__isset {
    _TaskTracker_scan_all_args__isset() : table_name(false), shard_id(false), cf_name(false) {}
    bool table_name :1;
    bool shard_id :1;
    bool cf_name :1;
} _TaskTracker_scan_all_args__isset;

class TaskTracker_scan_all_args {
public:

    static const char* ascii_fingerprint; // = "FA35BEC6F4D26D79A7E0AD1366489BCC";
    static const uint8_t binary_fingerprint[16]; // = {0xFA,0x35,0xBE,0xC6,0xF4,0xD2,0x6D,0x79,0xA7,0xE0,0xAD,0x13,0x66,0x48,0x9B,0xCC};

    TaskTracker_scan_all_args(const TaskTracker_scan_all_args&);
    TaskTracker_scan_all_args& operator=(const TaskTracker_scan_all_args&);
    TaskTracker_scan_all_args() : table_name(), shard_id(0), cf_name() {
    }

    virtual ~TaskTracker_scan_all_args() throw();
    std::string table_name;
    int64_t shard_id;
    std::string cf_name;

    _TaskTracker_scan_all_args__isset __isset;

    void __set_table_name(const std::string& val);

    void __set_shard_id(const int64_t val);

    void __set_cf_name(const std::string& val);

    bool operator == (const TaskTracker_scan_all_args & rhs) const {
        if (!(table_name == rhs.table_name))
            return false;
        if (!(shard_id == rhs.shard_id))
            return false;
        if (!(cf_name == rhs.cf_name))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_scan_all_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_scan_all_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_scan_all_args& obj);
};


class TaskTracker_scan_all_pargs {
public:

    static const char* ascii_fingerprint; // = "FA35BEC6F4D26D79A7E0AD1366489BCC";
    static const uint8_t binary_fingerprint[16]; // = {0xFA,0x35,0xBE,0xC6,0xF4,0xD2,0x6D,0x79,0xA7,0xE0,0xAD,0x13,0x66,0x48,0x9B,0xCC};


    virtual ~TaskTracker_scan_all_pargs() throw();
    const std::string* table_name;
    const int64_t* shard_id;
    const std::string* cf_name;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_scan_all_pargs& obj);
};

typedef struct _TaskTracker_scan_all_result__isset {
    _TaskTracker_scan_all_result__isset() : success(false) {}
    bool success :1;
} _TaskTracker_scan_all_result__isset;

class TaskTracker_scan_all_result {
public:

    static const char* ascii_fingerprint; // = "6AF8421C6A8DD64914A5D619FE6D5FEA";
    static const uint8_t binary_fingerprint[16]; // = {0x6A,0xF8,0x42,0x1C,0x6A,0x8D,0xD6,0x49,0x14,0xA5,0xD6,0x19,0xFE,0x6D,0x5F,0xEA};

    TaskTracker_scan_all_result(const TaskTracker_scan_all_result&);
    TaskTracker_scan_all_result& operator=(const TaskTracker_scan_all_result&);
    TaskTracker_scan_all_result() {
    }

    virtual ~TaskTracker_scan_all_result() throw();
    std::vector<std::vector<std::string> >  success;

    _TaskTracker_scan_all_result__isset __isset;

    void __set_success(const std::vector<std::vector<std::string> > & val);

    bool operator == (const TaskTracker_scan_all_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_scan_all_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_scan_all_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_scan_all_result& obj);
};

typedef struct _TaskTracker_scan_all_presult__isset {
    _TaskTracker_scan_all_presult__isset() : success(false) {}
    bool success :1;
} _TaskTracker_scan_all_presult__isset;

class TaskTracker_scan_all_presult {
public:

    static const char* ascii_fingerprint; // = "6AF8421C6A8DD64914A5D619FE6D5FEA";
    static const uint8_t binary_fingerprint[16]; // = {0x6A,0xF8,0x42,0x1C,0x6A,0x8D,0xD6,0x49,0x14,0xA5,0xD6,0x19,0xFE,0x6D,0x5F,0xEA};


    virtual ~TaskTracker_scan_all_presult() throw();
    std::vector<std::vector<std::string> > * success;

    _TaskTracker_scan_all_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_scan_all_presult& obj);
};

typedef struct _TaskTracker_scan_by_time_args__isset {
    _TaskTracker_scan_by_time_args__isset() : table_name(false), shard_id(false), cf_name(false), time_stamp(false) {}
    bool table_name :1;
    bool shard_id :1;
    bool cf_name :1;
    bool time_stamp :1;
} _TaskTracker_scan_by_time_args__isset;

class TaskTracker_scan_by_time_args {
public:

    static const char* ascii_fingerprint; // = "35DBF03AFE6CFC38FE634CDAF038307C";
    static const uint8_t binary_fingerprint[16]; // = {0x35,0xDB,0xF0,0x3A,0xFE,0x6C,0xFC,0x38,0xFE,0x63,0x4C,0xDA,0xF0,0x38,0x30,0x7C};

    TaskTracker_scan_by_time_args(const TaskTracker_scan_by_time_args&);
    TaskTracker_scan_by_time_args& operator=(const TaskTracker_scan_by_time_args&);
    TaskTracker_scan_by_time_args() : table_name(), shard_id(0), cf_name(), time_stamp(0) {
    }

    virtual ~TaskTracker_scan_by_time_args() throw();
    std::string table_name;
    int64_t shard_id;
    std::string cf_name;
    int64_t time_stamp;

    _TaskTracker_scan_by_time_args__isset __isset;

    void __set_table_name(const std::string& val);

    void __set_shard_id(const int64_t val);

    void __set_cf_name(const std::string& val);

    void __set_time_stamp(const int64_t val);

    bool operator == (const TaskTracker_scan_by_time_args & rhs) const {
        if (!(table_name == rhs.table_name))
            return false;
        if (!(shard_id == rhs.shard_id))
            return false;
        if (!(cf_name == rhs.cf_name))
            return false;
        if (!(time_stamp == rhs.time_stamp))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_scan_by_time_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_scan_by_time_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_scan_by_time_args& obj);
};


class TaskTracker_scan_by_time_pargs {
public:

    static const char* ascii_fingerprint; // = "35DBF03AFE6CFC38FE634CDAF038307C";
    static const uint8_t binary_fingerprint[16]; // = {0x35,0xDB,0xF0,0x3A,0xFE,0x6C,0xFC,0x38,0xFE,0x63,0x4C,0xDA,0xF0,0x38,0x30,0x7C};


    virtual ~TaskTracker_scan_by_time_pargs() throw();
    const std::string* table_name;
    const int64_t* shard_id;
    const std::string* cf_name;
    const int64_t* time_stamp;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_scan_by_time_pargs& obj);
};

typedef struct _TaskTracker_scan_by_time_result__isset {
    _TaskTracker_scan_by_time_result__isset() : success(false) {}
    bool success :1;
} _TaskTracker_scan_by_time_result__isset;

class TaskTracker_scan_by_time_result {
public:

    static const char* ascii_fingerprint; // = "6AF8421C6A8DD64914A5D619FE6D5FEA";
    static const uint8_t binary_fingerprint[16]; // = {0x6A,0xF8,0x42,0x1C,0x6A,0x8D,0xD6,0x49,0x14,0xA5,0xD6,0x19,0xFE,0x6D,0x5F,0xEA};

    TaskTracker_scan_by_time_result(const TaskTracker_scan_by_time_result&);
    TaskTracker_scan_by_time_result& operator=(const TaskTracker_scan_by_time_result&);
    TaskTracker_scan_by_time_result() {
    }

    virtual ~TaskTracker_scan_by_time_result() throw();
    std::vector<std::vector<std::string> >  success;

    _TaskTracker_scan_by_time_result__isset __isset;

    void __set_success(const std::vector<std::vector<std::string> > & val);

    bool operator == (const TaskTracker_scan_by_time_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const TaskTracker_scan_by_time_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const TaskTracker_scan_by_time_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_scan_by_time_result& obj);
};

typedef struct _TaskTracker_scan_by_time_presult__isset {
    _TaskTracker_scan_by_time_presult__isset() : success(false) {}
    bool success :1;
} _TaskTracker_scan_by_time_presult__isset;

class TaskTracker_scan_by_time_presult {
public:

    static const char* ascii_fingerprint; // = "6AF8421C6A8DD64914A5D619FE6D5FEA";
    static const uint8_t binary_fingerprint[16]; // = {0x6A,0xF8,0x42,0x1C,0x6A,0x8D,0xD6,0x49,0x14,0xA5,0xD6,0x19,0xFE,0x6D,0x5F,0xEA};


    virtual ~TaskTracker_scan_by_time_presult() throw();
    std::vector<std::vector<std::string> > * success;

    _TaskTracker_scan_by_time_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const TaskTracker_scan_by_time_presult& obj);
};

class TaskTrackerClient : virtual public TaskTrackerIf {
public:
    TaskTrackerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
        setProtocol(prot);
    }
    TaskTrackerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
        setProtocol(iprot,oprot);
    }
private:
    void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
        setProtocol(prot,prot);
    }
    void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
        piprot_=iprot;
        poprot_=oprot;
        iprot_ = iprot.get();
        oprot_ = oprot.get();
    }
public:
    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
        return piprot_;
    }
    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
        return poprot_;
    }
    void ping(std::string& _return);
    void send_ping();
    void recv_ping(std::string& _return);
    int64_t create_table(const TableProperty& table_property);
    void send_create_table(const TableProperty& table_property);
    int64_t recv_create_table();
    int64_t create_cf(const std::string& table_name, const ColumnFamilyProperty& cf_property);
    void send_create_cf(const std::string& table_name, const ColumnFamilyProperty& cf_property);
    int64_t recv_create_cf();
    int64_t vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const std::vector<std::string> & value);
    void send_vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const std::vector<std::string> & value);
    int64_t recv_vector_put();
    int64_t timely_vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const int64_t time_stampe, const std::vector<std::string> & value);
    void send_timely_vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const int64_t time_stampe, const std::vector<std::string> & value);
    int64_t recv_timely_vector_put();
    void vector_get(std::vector<std::string> & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key);
    void send_vector_get(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key);
    void recv_vector_get(std::vector<std::string> & _return);
    void scan_all(std::vector<std::vector<std::string> > & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name);
    void send_scan_all(const std::string& table_name, const int64_t shard_id, const std::string& cf_name);
    void recv_scan_all(std::vector<std::vector<std::string> > & _return);
    void scan_by_time(std::vector<std::vector<std::string> > & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const int64_t time_stamp);
    void send_scan_by_time(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const int64_t time_stamp);
    void recv_scan_by_time(std::vector<std::vector<std::string> > & _return);
protected:
    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
    ::apache::thrift::protocol::TProtocol* iprot_;
    ::apache::thrift::protocol::TProtocol* oprot_;
};

class TaskTrackerProcessor : public ::apache::thrift::TDispatchProcessor {
protected:
    boost::shared_ptr<TaskTrackerIf> iface_;
    virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
private:
    typedef  void (TaskTrackerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
    typedef std::map<std::string, ProcessFunction> ProcessMap;
    ProcessMap processMap_;
    void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_create_table(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_create_cf(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_vector_put(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_timely_vector_put(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_vector_get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_scan_all(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_scan_by_time(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
public:
    TaskTrackerProcessor(boost::shared_ptr<TaskTrackerIf> iface) :
        iface_(iface) {
        processMap_["ping"] = &TaskTrackerProcessor::process_ping;
        processMap_["create_table"] = &TaskTrackerProcessor::process_create_table;
        processMap_["create_cf"] = &TaskTrackerProcessor::process_create_cf;
        processMap_["vector_put"] = &TaskTrackerProcessor::process_vector_put;
        processMap_["timely_vector_put"] = &TaskTrackerProcessor::process_timely_vector_put;
        processMap_["vector_get"] = &TaskTrackerProcessor::process_vector_get;
        processMap_["scan_all"] = &TaskTrackerProcessor::process_scan_all;
        processMap_["scan_by_time"] = &TaskTrackerProcessor::process_scan_by_time;
    }

    virtual ~TaskTrackerProcessor() {}
};

class TaskTrackerProcessorFactory : public ::apache::thrift::TProcessorFactory {
public:
    TaskTrackerProcessorFactory(const ::boost::shared_ptr< TaskTrackerIfFactory >& handlerFactory) :
        handlerFactory_(handlerFactory) {}

    ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

protected:
    ::boost::shared_ptr< TaskTrackerIfFactory > handlerFactory_;
};

class TaskTrackerMultiface : virtual public TaskTrackerIf {
public:
    TaskTrackerMultiface(std::vector<boost::shared_ptr<TaskTrackerIf> >& ifaces) : ifaces_(ifaces) {
    }
    virtual ~TaskTrackerMultiface() {}
protected:
    std::vector<boost::shared_ptr<TaskTrackerIf> > ifaces_;
    TaskTrackerMultiface() {}
    void add(boost::shared_ptr<TaskTrackerIf> iface) {
        ifaces_.push_back(iface);
    }
public:
    void ping(std::string& _return) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->ping(_return);
        }
        ifaces_[i]->ping(_return);
        return;
    }

    int64_t create_table(const TableProperty& table_property) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->create_table(table_property);
        }
        return ifaces_[i]->create_table(table_property);
    }

    int64_t create_cf(const std::string& table_name, const ColumnFamilyProperty& cf_property) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->create_cf(table_name, cf_property);
        }
        return ifaces_[i]->create_cf(table_name, cf_property);
    }

    int64_t vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const std::vector<std::string> & value) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->vector_put(table_name, shard_id, cf_name, row_key, column_key, value);
        }
        return ifaces_[i]->vector_put(table_name, shard_id, cf_name, row_key, column_key, value);
    }

    int64_t timely_vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const int64_t time_stampe, const std::vector<std::string> & value) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->timely_vector_put(table_name, shard_id, cf_name, row_key, column_key, time_stampe, value);
        }
        return ifaces_[i]->timely_vector_put(table_name, shard_id, cf_name, row_key, column_key, time_stampe, value);
    }

    void vector_get(std::vector<std::string> & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->vector_get(_return, table_name, shard_id, cf_name, row_key, column_key);
        }
        ifaces_[i]->vector_get(_return, table_name, shard_id, cf_name, row_key, column_key);
        return;
    }

    void scan_all(std::vector<std::vector<std::string> > & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->scan_all(_return, table_name, shard_id, cf_name);
        }
        ifaces_[i]->scan_all(_return, table_name, shard_id, cf_name);
        return;
    }

    void scan_by_time(std::vector<std::vector<std::string> > & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const int64_t time_stamp) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->scan_by_time(_return, table_name, shard_id, cf_name, time_stamp);
        }
        ifaces_[i]->scan_by_time(_return, table_name, shard_id, cf_name, time_stamp);
        return;
    }

};

}
} // namespace

#endif
