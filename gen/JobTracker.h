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
#ifndef JobTracker_H
#define JobTracker_H

#include <thrift/TDispatchProcessor.h>
#include "Unicap_types.h"

namespace ntu {
namespace cap {

class JobTrackerIf {
public:
    virtual ~JobTrackerIf() {}
    virtual int64_t register_task_tracker(const int64_t node_id, const std::string& node_name, const int64_t storage_weight) = 0;
    virtual void get_all_task_tracker_info(std::map<int64_t, TaskTrackerInfo> & _return) = 0;
    virtual void fetch_cpu_task(TaskNode& _return, const int64_t task_tracker_id) = 0;
    virtual void fetch_gpu_task(TaskNode& _return, const int64_t task_tracker_id) = 0;
    virtual int64_t complete_cpu_task(const int64_t stage_id, const int64_t task_id) = 0;
    virtual int64_t complete_gpu_task(const int64_t stage_id, const int64_t task_id) = 0;
};

class JobTrackerIfFactory {
public:
    typedef JobTrackerIf Handler;

    virtual ~JobTrackerIfFactory() {}

    virtual JobTrackerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
    virtual void releaseHandler(JobTrackerIf* /* handler */) = 0;
};

class JobTrackerIfSingletonFactory : virtual public JobTrackerIfFactory {
public:
    JobTrackerIfSingletonFactory(const boost::shared_ptr<JobTrackerIf>& iface) : iface_(iface) {}
    virtual ~JobTrackerIfSingletonFactory() {}

    virtual JobTrackerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
        return iface_.get();
    }
    virtual void releaseHandler(JobTrackerIf* /* handler */) {}

protected:
    boost::shared_ptr<JobTrackerIf> iface_;
};

class JobTrackerNull : virtual public JobTrackerIf {
public:
    virtual ~JobTrackerNull() {}
    int64_t register_task_tracker(const int64_t /* node_id */, const std::string& /* node_name */, const int64_t /* storage_weight */) {
        int64_t _return = 0;
        return _return;
    }
    void get_all_task_tracker_info(std::map<int64_t, TaskTrackerInfo> & /* _return */) {
        return;
    }
    void fetch_cpu_task(TaskNode& /* _return */, const int64_t /* task_tracker_id */) {
        return;
    }
    void fetch_gpu_task(TaskNode& /* _return */, const int64_t /* task_tracker_id */) {
        return;
    }
    int64_t complete_cpu_task(const int64_t /* stage_id */, const int64_t /* task_id */) {
        int64_t _return = 0;
        return _return;
    }
    int64_t complete_gpu_task(const int64_t /* stage_id */, const int64_t /* task_id */) {
        int64_t _return = 0;
        return _return;
    }
};

typedef struct _JobTracker_register_task_tracker_args__isset {
    _JobTracker_register_task_tracker_args__isset() : node_id(false), node_name(false), storage_weight(false) {}
    bool node_id :1;
    bool node_name :1;
    bool storage_weight :1;
} _JobTracker_register_task_tracker_args__isset;

class JobTracker_register_task_tracker_args {
public:

    static const char* ascii_fingerprint; // = "FEBAC9C9DD701ABE5222D0CA33FDA432";
    static const uint8_t binary_fingerprint[16]; // = {0xFE,0xBA,0xC9,0xC9,0xDD,0x70,0x1A,0xBE,0x52,0x22,0xD0,0xCA,0x33,0xFD,0xA4,0x32};

    JobTracker_register_task_tracker_args(const JobTracker_register_task_tracker_args&);
    JobTracker_register_task_tracker_args& operator=(const JobTracker_register_task_tracker_args&);
    JobTracker_register_task_tracker_args() : node_id(0), node_name(), storage_weight(0) {
    }

    virtual ~JobTracker_register_task_tracker_args() throw();
    int64_t node_id;
    std::string node_name;
    int64_t storage_weight;

    _JobTracker_register_task_tracker_args__isset __isset;

    void __set_node_id(const int64_t val);

    void __set_node_name(const std::string& val);

    void __set_storage_weight(const int64_t val);

    bool operator == (const JobTracker_register_task_tracker_args & rhs) const {
        if (!(node_id == rhs.node_id))
            return false;
        if (!(node_name == rhs.node_name))
            return false;
        if (!(storage_weight == rhs.storage_weight))
            return false;
        return true;
    }
    bool operator != (const JobTracker_register_task_tracker_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_register_task_tracker_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_register_task_tracker_args& obj);
};


class JobTracker_register_task_tracker_pargs {
public:

    static const char* ascii_fingerprint; // = "FEBAC9C9DD701ABE5222D0CA33FDA432";
    static const uint8_t binary_fingerprint[16]; // = {0xFE,0xBA,0xC9,0xC9,0xDD,0x70,0x1A,0xBE,0x52,0x22,0xD0,0xCA,0x33,0xFD,0xA4,0x32};


    virtual ~JobTracker_register_task_tracker_pargs() throw();
    const int64_t* node_id;
    const std::string* node_name;
    const int64_t* storage_weight;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_register_task_tracker_pargs& obj);
};

typedef struct _JobTracker_register_task_tracker_result__isset {
    _JobTracker_register_task_tracker_result__isset() : success(false) {}
    bool success :1;
} _JobTracker_register_task_tracker_result__isset;

class JobTracker_register_task_tracker_result {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};

    JobTracker_register_task_tracker_result(const JobTracker_register_task_tracker_result&);
    JobTracker_register_task_tracker_result& operator=(const JobTracker_register_task_tracker_result&);
    JobTracker_register_task_tracker_result() : success(0) {
    }

    virtual ~JobTracker_register_task_tracker_result() throw();
    int64_t success;

    _JobTracker_register_task_tracker_result__isset __isset;

    void __set_success(const int64_t val);

    bool operator == (const JobTracker_register_task_tracker_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const JobTracker_register_task_tracker_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_register_task_tracker_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_register_task_tracker_result& obj);
};

typedef struct _JobTracker_register_task_tracker_presult__isset {
    _JobTracker_register_task_tracker_presult__isset() : success(false) {}
    bool success :1;
} _JobTracker_register_task_tracker_presult__isset;

class JobTracker_register_task_tracker_presult {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};


    virtual ~JobTracker_register_task_tracker_presult() throw();
    int64_t* success;

    _JobTracker_register_task_tracker_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_register_task_tracker_presult& obj);
};


class JobTracker_get_all_task_tracker_info_args {
public:

    static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
    static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};

    JobTracker_get_all_task_tracker_info_args(const JobTracker_get_all_task_tracker_info_args&);
    JobTracker_get_all_task_tracker_info_args& operator=(const JobTracker_get_all_task_tracker_info_args&);
    JobTracker_get_all_task_tracker_info_args() {
    }

    virtual ~JobTracker_get_all_task_tracker_info_args() throw();

    bool operator == (const JobTracker_get_all_task_tracker_info_args & /* rhs */) const {
        return true;
    }
    bool operator != (const JobTracker_get_all_task_tracker_info_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_get_all_task_tracker_info_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_get_all_task_tracker_info_args& obj);
};


class JobTracker_get_all_task_tracker_info_pargs {
public:

    static const char* ascii_fingerprint; // = "99914B932BD37A50B983C5E7C90AE93B";
    static const uint8_t binary_fingerprint[16]; // = {0x99,0x91,0x4B,0x93,0x2B,0xD3,0x7A,0x50,0xB9,0x83,0xC5,0xE7,0xC9,0x0A,0xE9,0x3B};


    virtual ~JobTracker_get_all_task_tracker_info_pargs() throw();

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_get_all_task_tracker_info_pargs& obj);
};

typedef struct _JobTracker_get_all_task_tracker_info_result__isset {
    _JobTracker_get_all_task_tracker_info_result__isset() : success(false) {}
    bool success :1;
} _JobTracker_get_all_task_tracker_info_result__isset;

class JobTracker_get_all_task_tracker_info_result {
public:

    static const char* ascii_fingerprint; // = "91CFAC4E50ED06EF3A917778CA763D7C";
    static const uint8_t binary_fingerprint[16]; // = {0x91,0xCF,0xAC,0x4E,0x50,0xED,0x06,0xEF,0x3A,0x91,0x77,0x78,0xCA,0x76,0x3D,0x7C};

    JobTracker_get_all_task_tracker_info_result(const JobTracker_get_all_task_tracker_info_result&);
    JobTracker_get_all_task_tracker_info_result& operator=(const JobTracker_get_all_task_tracker_info_result&);
    JobTracker_get_all_task_tracker_info_result() {
    }

    virtual ~JobTracker_get_all_task_tracker_info_result() throw();
    std::map<int64_t, TaskTrackerInfo>  success;

    _JobTracker_get_all_task_tracker_info_result__isset __isset;

    void __set_success(const std::map<int64_t, TaskTrackerInfo> & val);

    bool operator == (const JobTracker_get_all_task_tracker_info_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const JobTracker_get_all_task_tracker_info_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_get_all_task_tracker_info_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_get_all_task_tracker_info_result& obj);
};

typedef struct _JobTracker_get_all_task_tracker_info_presult__isset {
    _JobTracker_get_all_task_tracker_info_presult__isset() : success(false) {}
    bool success :1;
} _JobTracker_get_all_task_tracker_info_presult__isset;

class JobTracker_get_all_task_tracker_info_presult {
public:

    static const char* ascii_fingerprint; // = "91CFAC4E50ED06EF3A917778CA763D7C";
    static const uint8_t binary_fingerprint[16]; // = {0x91,0xCF,0xAC,0x4E,0x50,0xED,0x06,0xEF,0x3A,0x91,0x77,0x78,0xCA,0x76,0x3D,0x7C};


    virtual ~JobTracker_get_all_task_tracker_info_presult() throw();
    std::map<int64_t, TaskTrackerInfo> * success;

    _JobTracker_get_all_task_tracker_info_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_get_all_task_tracker_info_presult& obj);
};

typedef struct _JobTracker_fetch_cpu_task_args__isset {
    _JobTracker_fetch_cpu_task_args__isset() : task_tracker_id(false) {}
    bool task_tracker_id :1;
} _JobTracker_fetch_cpu_task_args__isset;

class JobTracker_fetch_cpu_task_args {
public:

    static const char* ascii_fingerprint; // = "56A59CE7FFAF82BCA8A19FAACDE4FB75";
    static const uint8_t binary_fingerprint[16]; // = {0x56,0xA5,0x9C,0xE7,0xFF,0xAF,0x82,0xBC,0xA8,0xA1,0x9F,0xAA,0xCD,0xE4,0xFB,0x75};

    JobTracker_fetch_cpu_task_args(const JobTracker_fetch_cpu_task_args&);
    JobTracker_fetch_cpu_task_args& operator=(const JobTracker_fetch_cpu_task_args&);
    JobTracker_fetch_cpu_task_args() : task_tracker_id(0) {
    }

    virtual ~JobTracker_fetch_cpu_task_args() throw();
    int64_t task_tracker_id;

    _JobTracker_fetch_cpu_task_args__isset __isset;

    void __set_task_tracker_id(const int64_t val);

    bool operator == (const JobTracker_fetch_cpu_task_args & rhs) const {
        if (!(task_tracker_id == rhs.task_tracker_id))
            return false;
        return true;
    }
    bool operator != (const JobTracker_fetch_cpu_task_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_fetch_cpu_task_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_fetch_cpu_task_args& obj);
};


class JobTracker_fetch_cpu_task_pargs {
public:

    static const char* ascii_fingerprint; // = "56A59CE7FFAF82BCA8A19FAACDE4FB75";
    static const uint8_t binary_fingerprint[16]; // = {0x56,0xA5,0x9C,0xE7,0xFF,0xAF,0x82,0xBC,0xA8,0xA1,0x9F,0xAA,0xCD,0xE4,0xFB,0x75};


    virtual ~JobTracker_fetch_cpu_task_pargs() throw();
    const int64_t* task_tracker_id;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_fetch_cpu_task_pargs& obj);
};

typedef struct _JobTracker_fetch_cpu_task_result__isset {
    _JobTracker_fetch_cpu_task_result__isset() : success(false) {}
    bool success :1;
} _JobTracker_fetch_cpu_task_result__isset;

class JobTracker_fetch_cpu_task_result {
public:

    static const char* ascii_fingerprint; // = "D860527690E7078EF4FD5C2B70E07C96";
    static const uint8_t binary_fingerprint[16]; // = {0xD8,0x60,0x52,0x76,0x90,0xE7,0x07,0x8E,0xF4,0xFD,0x5C,0x2B,0x70,0xE0,0x7C,0x96};

    JobTracker_fetch_cpu_task_result(const JobTracker_fetch_cpu_task_result&);
    JobTracker_fetch_cpu_task_result& operator=(const JobTracker_fetch_cpu_task_result&);
    JobTracker_fetch_cpu_task_result() {
    }

    virtual ~JobTracker_fetch_cpu_task_result() throw();
    TaskNode success;

    _JobTracker_fetch_cpu_task_result__isset __isset;

    void __set_success(const TaskNode& val);

    bool operator == (const JobTracker_fetch_cpu_task_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const JobTracker_fetch_cpu_task_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_fetch_cpu_task_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_fetch_cpu_task_result& obj);
};

typedef struct _JobTracker_fetch_cpu_task_presult__isset {
    _JobTracker_fetch_cpu_task_presult__isset() : success(false) {}
    bool success :1;
} _JobTracker_fetch_cpu_task_presult__isset;

class JobTracker_fetch_cpu_task_presult {
public:

    static const char* ascii_fingerprint; // = "D860527690E7078EF4FD5C2B70E07C96";
    static const uint8_t binary_fingerprint[16]; // = {0xD8,0x60,0x52,0x76,0x90,0xE7,0x07,0x8E,0xF4,0xFD,0x5C,0x2B,0x70,0xE0,0x7C,0x96};


    virtual ~JobTracker_fetch_cpu_task_presult() throw();
    TaskNode* success;

    _JobTracker_fetch_cpu_task_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_fetch_cpu_task_presult& obj);
};

typedef struct _JobTracker_fetch_gpu_task_args__isset {
    _JobTracker_fetch_gpu_task_args__isset() : task_tracker_id(false) {}
    bool task_tracker_id :1;
} _JobTracker_fetch_gpu_task_args__isset;

class JobTracker_fetch_gpu_task_args {
public:

    static const char* ascii_fingerprint; // = "56A59CE7FFAF82BCA8A19FAACDE4FB75";
    static const uint8_t binary_fingerprint[16]; // = {0x56,0xA5,0x9C,0xE7,0xFF,0xAF,0x82,0xBC,0xA8,0xA1,0x9F,0xAA,0xCD,0xE4,0xFB,0x75};

    JobTracker_fetch_gpu_task_args(const JobTracker_fetch_gpu_task_args&);
    JobTracker_fetch_gpu_task_args& operator=(const JobTracker_fetch_gpu_task_args&);
    JobTracker_fetch_gpu_task_args() : task_tracker_id(0) {
    }

    virtual ~JobTracker_fetch_gpu_task_args() throw();
    int64_t task_tracker_id;

    _JobTracker_fetch_gpu_task_args__isset __isset;

    void __set_task_tracker_id(const int64_t val);

    bool operator == (const JobTracker_fetch_gpu_task_args & rhs) const {
        if (!(task_tracker_id == rhs.task_tracker_id))
            return false;
        return true;
    }
    bool operator != (const JobTracker_fetch_gpu_task_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_fetch_gpu_task_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_fetch_gpu_task_args& obj);
};


class JobTracker_fetch_gpu_task_pargs {
public:

    static const char* ascii_fingerprint; // = "56A59CE7FFAF82BCA8A19FAACDE4FB75";
    static const uint8_t binary_fingerprint[16]; // = {0x56,0xA5,0x9C,0xE7,0xFF,0xAF,0x82,0xBC,0xA8,0xA1,0x9F,0xAA,0xCD,0xE4,0xFB,0x75};


    virtual ~JobTracker_fetch_gpu_task_pargs() throw();
    const int64_t* task_tracker_id;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_fetch_gpu_task_pargs& obj);
};

typedef struct _JobTracker_fetch_gpu_task_result__isset {
    _JobTracker_fetch_gpu_task_result__isset() : success(false) {}
    bool success :1;
} _JobTracker_fetch_gpu_task_result__isset;

class JobTracker_fetch_gpu_task_result {
public:

    static const char* ascii_fingerprint; // = "D860527690E7078EF4FD5C2B70E07C96";
    static const uint8_t binary_fingerprint[16]; // = {0xD8,0x60,0x52,0x76,0x90,0xE7,0x07,0x8E,0xF4,0xFD,0x5C,0x2B,0x70,0xE0,0x7C,0x96};

    JobTracker_fetch_gpu_task_result(const JobTracker_fetch_gpu_task_result&);
    JobTracker_fetch_gpu_task_result& operator=(const JobTracker_fetch_gpu_task_result&);
    JobTracker_fetch_gpu_task_result() {
    }

    virtual ~JobTracker_fetch_gpu_task_result() throw();
    TaskNode success;

    _JobTracker_fetch_gpu_task_result__isset __isset;

    void __set_success(const TaskNode& val);

    bool operator == (const JobTracker_fetch_gpu_task_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const JobTracker_fetch_gpu_task_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_fetch_gpu_task_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_fetch_gpu_task_result& obj);
};

typedef struct _JobTracker_fetch_gpu_task_presult__isset {
    _JobTracker_fetch_gpu_task_presult__isset() : success(false) {}
    bool success :1;
} _JobTracker_fetch_gpu_task_presult__isset;

class JobTracker_fetch_gpu_task_presult {
public:

    static const char* ascii_fingerprint; // = "D860527690E7078EF4FD5C2B70E07C96";
    static const uint8_t binary_fingerprint[16]; // = {0xD8,0x60,0x52,0x76,0x90,0xE7,0x07,0x8E,0xF4,0xFD,0x5C,0x2B,0x70,0xE0,0x7C,0x96};


    virtual ~JobTracker_fetch_gpu_task_presult() throw();
    TaskNode* success;

    _JobTracker_fetch_gpu_task_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_fetch_gpu_task_presult& obj);
};

typedef struct _JobTracker_complete_cpu_task_args__isset {
    _JobTracker_complete_cpu_task_args__isset() : stage_id(false), task_id(false) {}
    bool stage_id :1;
    bool task_id :1;
} _JobTracker_complete_cpu_task_args__isset;

class JobTracker_complete_cpu_task_args {
public:

    static const char* ascii_fingerprint; // = "F33135321253DAEB67B0E79E416CA831";
    static const uint8_t binary_fingerprint[16]; // = {0xF3,0x31,0x35,0x32,0x12,0x53,0xDA,0xEB,0x67,0xB0,0xE7,0x9E,0x41,0x6C,0xA8,0x31};

    JobTracker_complete_cpu_task_args(const JobTracker_complete_cpu_task_args&);
    JobTracker_complete_cpu_task_args& operator=(const JobTracker_complete_cpu_task_args&);
    JobTracker_complete_cpu_task_args() : stage_id(0), task_id(0) {
    }

    virtual ~JobTracker_complete_cpu_task_args() throw();
    int64_t stage_id;
    int64_t task_id;

    _JobTracker_complete_cpu_task_args__isset __isset;

    void __set_stage_id(const int64_t val);

    void __set_task_id(const int64_t val);

    bool operator == (const JobTracker_complete_cpu_task_args & rhs) const {
        if (!(stage_id == rhs.stage_id))
            return false;
        if (!(task_id == rhs.task_id))
            return false;
        return true;
    }
    bool operator != (const JobTracker_complete_cpu_task_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_complete_cpu_task_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_complete_cpu_task_args& obj);
};


class JobTracker_complete_cpu_task_pargs {
public:

    static const char* ascii_fingerprint; // = "F33135321253DAEB67B0E79E416CA831";
    static const uint8_t binary_fingerprint[16]; // = {0xF3,0x31,0x35,0x32,0x12,0x53,0xDA,0xEB,0x67,0xB0,0xE7,0x9E,0x41,0x6C,0xA8,0x31};


    virtual ~JobTracker_complete_cpu_task_pargs() throw();
    const int64_t* stage_id;
    const int64_t* task_id;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_complete_cpu_task_pargs& obj);
};

typedef struct _JobTracker_complete_cpu_task_result__isset {
    _JobTracker_complete_cpu_task_result__isset() : success(false) {}
    bool success :1;
} _JobTracker_complete_cpu_task_result__isset;

class JobTracker_complete_cpu_task_result {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};

    JobTracker_complete_cpu_task_result(const JobTracker_complete_cpu_task_result&);
    JobTracker_complete_cpu_task_result& operator=(const JobTracker_complete_cpu_task_result&);
    JobTracker_complete_cpu_task_result() : success(0) {
    }

    virtual ~JobTracker_complete_cpu_task_result() throw();
    int64_t success;

    _JobTracker_complete_cpu_task_result__isset __isset;

    void __set_success(const int64_t val);

    bool operator == (const JobTracker_complete_cpu_task_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const JobTracker_complete_cpu_task_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_complete_cpu_task_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_complete_cpu_task_result& obj);
};

typedef struct _JobTracker_complete_cpu_task_presult__isset {
    _JobTracker_complete_cpu_task_presult__isset() : success(false) {}
    bool success :1;
} _JobTracker_complete_cpu_task_presult__isset;

class JobTracker_complete_cpu_task_presult {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};


    virtual ~JobTracker_complete_cpu_task_presult() throw();
    int64_t* success;

    _JobTracker_complete_cpu_task_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_complete_cpu_task_presult& obj);
};

typedef struct _JobTracker_complete_gpu_task_args__isset {
    _JobTracker_complete_gpu_task_args__isset() : stage_id(false), task_id(false) {}
    bool stage_id :1;
    bool task_id :1;
} _JobTracker_complete_gpu_task_args__isset;

class JobTracker_complete_gpu_task_args {
public:

    static const char* ascii_fingerprint; // = "F33135321253DAEB67B0E79E416CA831";
    static const uint8_t binary_fingerprint[16]; // = {0xF3,0x31,0x35,0x32,0x12,0x53,0xDA,0xEB,0x67,0xB0,0xE7,0x9E,0x41,0x6C,0xA8,0x31};

    JobTracker_complete_gpu_task_args(const JobTracker_complete_gpu_task_args&);
    JobTracker_complete_gpu_task_args& operator=(const JobTracker_complete_gpu_task_args&);
    JobTracker_complete_gpu_task_args() : stage_id(0), task_id(0) {
    }

    virtual ~JobTracker_complete_gpu_task_args() throw();
    int64_t stage_id;
    int64_t task_id;

    _JobTracker_complete_gpu_task_args__isset __isset;

    void __set_stage_id(const int64_t val);

    void __set_task_id(const int64_t val);

    bool operator == (const JobTracker_complete_gpu_task_args & rhs) const {
        if (!(stage_id == rhs.stage_id))
            return false;
        if (!(task_id == rhs.task_id))
            return false;
        return true;
    }
    bool operator != (const JobTracker_complete_gpu_task_args &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_complete_gpu_task_args & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_complete_gpu_task_args& obj);
};


class JobTracker_complete_gpu_task_pargs {
public:

    static const char* ascii_fingerprint; // = "F33135321253DAEB67B0E79E416CA831";
    static const uint8_t binary_fingerprint[16]; // = {0xF3,0x31,0x35,0x32,0x12,0x53,0xDA,0xEB,0x67,0xB0,0xE7,0x9E,0x41,0x6C,0xA8,0x31};


    virtual ~JobTracker_complete_gpu_task_pargs() throw();
    const int64_t* stage_id;
    const int64_t* task_id;

    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_complete_gpu_task_pargs& obj);
};

typedef struct _JobTracker_complete_gpu_task_result__isset {
    _JobTracker_complete_gpu_task_result__isset() : success(false) {}
    bool success :1;
} _JobTracker_complete_gpu_task_result__isset;

class JobTracker_complete_gpu_task_result {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};

    JobTracker_complete_gpu_task_result(const JobTracker_complete_gpu_task_result&);
    JobTracker_complete_gpu_task_result& operator=(const JobTracker_complete_gpu_task_result&);
    JobTracker_complete_gpu_task_result() : success(0) {
    }

    virtual ~JobTracker_complete_gpu_task_result() throw();
    int64_t success;

    _JobTracker_complete_gpu_task_result__isset __isset;

    void __set_success(const int64_t val);

    bool operator == (const JobTracker_complete_gpu_task_result & rhs) const {
        if (!(success == rhs.success))
            return false;
        return true;
    }
    bool operator != (const JobTracker_complete_gpu_task_result &rhs) const {
        return !(*this == rhs);
    }

    bool operator < (const JobTracker_complete_gpu_task_result & ) const;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_complete_gpu_task_result& obj);
};

typedef struct _JobTracker_complete_gpu_task_presult__isset {
    _JobTracker_complete_gpu_task_presult__isset() : success(false) {}
    bool success :1;
} _JobTracker_complete_gpu_task_presult__isset;

class JobTracker_complete_gpu_task_presult {
public:

    static const char* ascii_fingerprint; // = "1CF279170B7E876D4ABB450CC8994359";
    static const uint8_t binary_fingerprint[16]; // = {0x1C,0xF2,0x79,0x17,0x0B,0x7E,0x87,0x6D,0x4A,0xBB,0x45,0x0C,0xC8,0x99,0x43,0x59};


    virtual ~JobTracker_complete_gpu_task_presult() throw();
    int64_t* success;

    _JobTracker_complete_gpu_task_presult__isset __isset;

    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

    friend std::ostream& operator<<(std::ostream& out, const JobTracker_complete_gpu_task_presult& obj);
};

class JobTrackerClient : virtual public JobTrackerIf {
public:
    JobTrackerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
        setProtocol(prot);
    }
    JobTrackerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
    int64_t register_task_tracker(const int64_t node_id, const std::string& node_name, const int64_t storage_weight);
    void send_register_task_tracker(const int64_t node_id, const std::string& node_name, const int64_t storage_weight);
    int64_t recv_register_task_tracker();
    void get_all_task_tracker_info(std::map<int64_t, TaskTrackerInfo> & _return);
    void send_get_all_task_tracker_info();
    void recv_get_all_task_tracker_info(std::map<int64_t, TaskTrackerInfo> & _return);
    void fetch_cpu_task(TaskNode& _return, const int64_t task_tracker_id);
    void send_fetch_cpu_task(const int64_t task_tracker_id);
    void recv_fetch_cpu_task(TaskNode& _return);
    void fetch_gpu_task(TaskNode& _return, const int64_t task_tracker_id);
    void send_fetch_gpu_task(const int64_t task_tracker_id);
    void recv_fetch_gpu_task(TaskNode& _return);
    int64_t complete_cpu_task(const int64_t stage_id, const int64_t task_id);
    void send_complete_cpu_task(const int64_t stage_id, const int64_t task_id);
    int64_t recv_complete_cpu_task();
    int64_t complete_gpu_task(const int64_t stage_id, const int64_t task_id);
    void send_complete_gpu_task(const int64_t stage_id, const int64_t task_id);
    int64_t recv_complete_gpu_task();
protected:
    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
    ::apache::thrift::protocol::TProtocol* iprot_;
    ::apache::thrift::protocol::TProtocol* oprot_;
};

class JobTrackerProcessor : public ::apache::thrift::TDispatchProcessor {
protected:
    boost::shared_ptr<JobTrackerIf> iface_;
    virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
private:
    typedef  void (JobTrackerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
    typedef std::map<std::string, ProcessFunction> ProcessMap;
    ProcessMap processMap_;
    void process_register_task_tracker(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_get_all_task_tracker_info(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_fetch_cpu_task(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_fetch_gpu_task(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_complete_cpu_task(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
    void process_complete_gpu_task(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
public:
    JobTrackerProcessor(boost::shared_ptr<JobTrackerIf> iface) :
        iface_(iface) {
        processMap_["register_task_tracker"] = &JobTrackerProcessor::process_register_task_tracker;
        processMap_["get_all_task_tracker_info"] = &JobTrackerProcessor::process_get_all_task_tracker_info;
        processMap_["fetch_cpu_task"] = &JobTrackerProcessor::process_fetch_cpu_task;
        processMap_["fetch_gpu_task"] = &JobTrackerProcessor::process_fetch_gpu_task;
        processMap_["complete_cpu_task"] = &JobTrackerProcessor::process_complete_cpu_task;
        processMap_["complete_gpu_task"] = &JobTrackerProcessor::process_complete_gpu_task;
    }

    virtual ~JobTrackerProcessor() {}
};

class JobTrackerProcessorFactory : public ::apache::thrift::TProcessorFactory {
public:
    JobTrackerProcessorFactory(const ::boost::shared_ptr< JobTrackerIfFactory >& handlerFactory) :
        handlerFactory_(handlerFactory) {}

    ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

protected:
    ::boost::shared_ptr< JobTrackerIfFactory > handlerFactory_;
};

class JobTrackerMultiface : virtual public JobTrackerIf {
public:
    JobTrackerMultiface(std::vector<boost::shared_ptr<JobTrackerIf> >& ifaces) : ifaces_(ifaces) {
    }
    virtual ~JobTrackerMultiface() {}
protected:
    std::vector<boost::shared_ptr<JobTrackerIf> > ifaces_;
    JobTrackerMultiface() {}
    void add(boost::shared_ptr<JobTrackerIf> iface) {
        ifaces_.push_back(iface);
    }
public:
    int64_t register_task_tracker(const int64_t node_id, const std::string& node_name, const int64_t storage_weight) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->register_task_tracker(node_id, node_name, storage_weight);
        }
        return ifaces_[i]->register_task_tracker(node_id, node_name, storage_weight);
    }

    void get_all_task_tracker_info(std::map<int64_t, TaskTrackerInfo> & _return) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->get_all_task_tracker_info(_return);
        }
        ifaces_[i]->get_all_task_tracker_info(_return);
        return;
    }

    void fetch_cpu_task(TaskNode& _return, const int64_t task_tracker_id) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->fetch_cpu_task(_return, task_tracker_id);
        }
        ifaces_[i]->fetch_cpu_task(_return, task_tracker_id);
        return;
    }

    void fetch_gpu_task(TaskNode& _return, const int64_t task_tracker_id) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->fetch_gpu_task(_return, task_tracker_id);
        }
        ifaces_[i]->fetch_gpu_task(_return, task_tracker_id);
        return;
    }

    int64_t complete_cpu_task(const int64_t stage_id, const int64_t task_id) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->complete_cpu_task(stage_id, task_id);
        }
        return ifaces_[i]->complete_cpu_task(stage_id, task_id);
    }

    int64_t complete_gpu_task(const int64_t stage_id, const int64_t task_id) {
        size_t sz = ifaces_.size();
        size_t i = 0;
        for (; i < (sz - 1); ++i) {
            ifaces_[i]->complete_gpu_task(stage_id, task_id);
        }
        return ifaces_[i]->complete_gpu_task(stage_id, task_id);
    }

};

}
} // namespace

#endif
