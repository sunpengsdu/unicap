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
#include "JobTracker.h"

namespace ntu {
namespace cap {


JobTracker_register_task_tracker_args::~JobTracker_register_task_tracker_args() throw() {
}


uint32_t JobTracker_register_task_tracker_args::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 1:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->node_id);
                this->__isset.node_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->node_name);
                this->__isset.node_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 3:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->storage_weight);
                this->__isset.storage_weight = true;
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

    return xfer;
}

uint32_t JobTracker_register_task_tracker_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_register_task_tracker_args");

    xfer += oprot->writeFieldBegin("node_id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->node_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("node_name", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->node_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("storage_weight", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->storage_weight);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_register_task_tracker_pargs::~JobTracker_register_task_tracker_pargs() throw() {
}


uint32_t JobTracker_register_task_tracker_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_register_task_tracker_pargs");

    xfer += oprot->writeFieldBegin("node_id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64((*(this->node_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("node_name", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString((*(this->node_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("storage_weight", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64((*(this->storage_weight)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_register_task_tracker_result::~JobTracker_register_task_tracker_result() throw() {
}


uint32_t JobTracker_register_task_tracker_result::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->success);
                this->__isset.success = true;
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

    return xfer;
}

uint32_t JobTracker_register_task_tracker_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("JobTracker_register_task_tracker_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
        xfer += oprot->writeI64(this->success);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


JobTracker_register_task_tracker_presult::~JobTracker_register_task_tracker_presult() throw() {
}


uint32_t JobTracker_register_task_tracker_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64((*(this->success)));
                this->__isset.success = true;
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

    return xfer;
}


JobTracker_get_all_task_tracker_info_args::~JobTracker_get_all_task_tracker_info_args() throw() {
}


uint32_t JobTracker_get_all_task_tracker_info_args::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        xfer += iprot->skip(ftype);
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t JobTracker_get_all_task_tracker_info_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_get_all_task_tracker_info_args");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_get_all_task_tracker_info_pargs::~JobTracker_get_all_task_tracker_info_pargs() throw() {
}


uint32_t JobTracker_get_all_task_tracker_info_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_get_all_task_tracker_info_pargs");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_get_all_task_tracker_info_result::~JobTracker_get_all_task_tracker_info_result() throw() {
}


uint32_t JobTracker_get_all_task_tracker_info_result::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_MAP) {
                {
                    this->success.clear();
                    uint32_t _size42;
                    ::apache::thrift::protocol::TType _ktype43;
                    ::apache::thrift::protocol::TType _vtype44;
                    xfer += iprot->readMapBegin(_ktype43, _vtype44, _size42);
                    uint32_t _i46;
                    for (_i46 = 0; _i46 < _size42; ++_i46) {
                        int64_t _key47;
                        xfer += iprot->readI64(_key47);
                        TaskTrackerInfo& _val48 = this->success[_key47];
                        xfer += _val48.read(iprot);
                    }
                    xfer += iprot->readMapEnd();
                }
                this->__isset.success = true;
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

    return xfer;
}

uint32_t JobTracker_get_all_task_tracker_info_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("JobTracker_get_all_task_tracker_info_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_MAP, 0);
        {
            xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I64, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->success.size()));
            std::map<int64_t, TaskTrackerInfo> ::const_iterator _iter49;
            for (_iter49 = this->success.begin(); _iter49 != this->success.end(); ++_iter49) {
                xfer += oprot->writeI64(_iter49->first);
                xfer += _iter49->second.write(oprot);
            }
            xfer += oprot->writeMapEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


JobTracker_get_all_task_tracker_info_presult::~JobTracker_get_all_task_tracker_info_presult() throw() {
}


uint32_t JobTracker_get_all_task_tracker_info_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_MAP) {
                {
                    (*(this->success)).clear();
                    uint32_t _size50;
                    ::apache::thrift::protocol::TType _ktype51;
                    ::apache::thrift::protocol::TType _vtype52;
                    xfer += iprot->readMapBegin(_ktype51, _vtype52, _size50);
                    uint32_t _i54;
                    for (_i54 = 0; _i54 < _size50; ++_i54) {
                        int64_t _key55;
                        xfer += iprot->readI64(_key55);
                        TaskTrackerInfo& _val56 = (*(this->success))[_key55];
                        xfer += _val56.read(iprot);
                    }
                    xfer += iprot->readMapEnd();
                }
                this->__isset.success = true;
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

    return xfer;
}


JobTracker_fetch_cpu_task_args::~JobTracker_fetch_cpu_task_args() throw() {
}


uint32_t JobTracker_fetch_cpu_task_args::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 1:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->task_tracker_id);
                this->__isset.task_tracker_id = true;
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

    return xfer;
}

uint32_t JobTracker_fetch_cpu_task_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_fetch_cpu_task_args");

    xfer += oprot->writeFieldBegin("task_tracker_id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->task_tracker_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_fetch_cpu_task_pargs::~JobTracker_fetch_cpu_task_pargs() throw() {
}


uint32_t JobTracker_fetch_cpu_task_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_fetch_cpu_task_pargs");

    xfer += oprot->writeFieldBegin("task_tracker_id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64((*(this->task_tracker_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_fetch_cpu_task_result::~JobTracker_fetch_cpu_task_result() throw() {
}


uint32_t JobTracker_fetch_cpu_task_result::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                xfer += this->success.read(iprot);
                this->__isset.success = true;
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

    return xfer;
}

uint32_t JobTracker_fetch_cpu_task_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("JobTracker_fetch_cpu_task_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRUCT, 0);
        xfer += this->success.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


JobTracker_fetch_cpu_task_presult::~JobTracker_fetch_cpu_task_presult() throw() {
}


uint32_t JobTracker_fetch_cpu_task_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                xfer += (*(this->success)).read(iprot);
                this->__isset.success = true;
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

    return xfer;
}


JobTracker_fetch_gpu_task_args::~JobTracker_fetch_gpu_task_args() throw() {
}


uint32_t JobTracker_fetch_gpu_task_args::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 1:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->task_tracker_id);
                this->__isset.task_tracker_id = true;
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

    return xfer;
}

uint32_t JobTracker_fetch_gpu_task_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_fetch_gpu_task_args");

    xfer += oprot->writeFieldBegin("task_tracker_id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->task_tracker_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_fetch_gpu_task_pargs::~JobTracker_fetch_gpu_task_pargs() throw() {
}


uint32_t JobTracker_fetch_gpu_task_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_fetch_gpu_task_pargs");

    xfer += oprot->writeFieldBegin("task_tracker_id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64((*(this->task_tracker_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_fetch_gpu_task_result::~JobTracker_fetch_gpu_task_result() throw() {
}


uint32_t JobTracker_fetch_gpu_task_result::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                xfer += this->success.read(iprot);
                this->__isset.success = true;
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

    return xfer;
}

uint32_t JobTracker_fetch_gpu_task_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("JobTracker_fetch_gpu_task_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRUCT, 0);
        xfer += this->success.write(oprot);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


JobTracker_fetch_gpu_task_presult::~JobTracker_fetch_gpu_task_presult() throw() {
}


uint32_t JobTracker_fetch_gpu_task_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                xfer += (*(this->success)).read(iprot);
                this->__isset.success = true;
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

    return xfer;
}


JobTracker_complete_cpu_task_args::~JobTracker_complete_cpu_task_args() throw() {
}


uint32_t JobTracker_complete_cpu_task_args::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 1:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->stage_id);
                this->__isset.stage_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->task_id);
                this->__isset.task_id = true;
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

    return xfer;
}

uint32_t JobTracker_complete_cpu_task_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_complete_cpu_task_args");

    xfer += oprot->writeFieldBegin("stage_id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->stage_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("task_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->task_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_complete_cpu_task_pargs::~JobTracker_complete_cpu_task_pargs() throw() {
}


uint32_t JobTracker_complete_cpu_task_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_complete_cpu_task_pargs");

    xfer += oprot->writeFieldBegin("stage_id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64((*(this->stage_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("task_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64((*(this->task_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_complete_cpu_task_result::~JobTracker_complete_cpu_task_result() throw() {
}


uint32_t JobTracker_complete_cpu_task_result::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->success);
                this->__isset.success = true;
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

    return xfer;
}

uint32_t JobTracker_complete_cpu_task_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("JobTracker_complete_cpu_task_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
        xfer += oprot->writeI64(this->success);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


JobTracker_complete_cpu_task_presult::~JobTracker_complete_cpu_task_presult() throw() {
}


uint32_t JobTracker_complete_cpu_task_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64((*(this->success)));
                this->__isset.success = true;
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

    return xfer;
}


JobTracker_complete_gpu_task_args::~JobTracker_complete_gpu_task_args() throw() {
}


uint32_t JobTracker_complete_gpu_task_args::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 1:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->stage_id);
                this->__isset.stage_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->task_id);
                this->__isset.task_id = true;
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

    return xfer;
}

uint32_t JobTracker_complete_gpu_task_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_complete_gpu_task_args");

    xfer += oprot->writeFieldBegin("stage_id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->stage_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("task_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->task_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_complete_gpu_task_pargs::~JobTracker_complete_gpu_task_pargs() throw() {
}


uint32_t JobTracker_complete_gpu_task_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("JobTracker_complete_gpu_task_pargs");

    xfer += oprot->writeFieldBegin("stage_id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64((*(this->stage_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("task_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64((*(this->task_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


JobTracker_complete_gpu_task_result::~JobTracker_complete_gpu_task_result() throw() {
}


uint32_t JobTracker_complete_gpu_task_result::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->success);
                this->__isset.success = true;
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

    return xfer;
}

uint32_t JobTracker_complete_gpu_task_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("JobTracker_complete_gpu_task_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
        xfer += oprot->writeI64(this->success);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


JobTracker_complete_gpu_task_presult::~JobTracker_complete_gpu_task_presult() throw() {
}


uint32_t JobTracker_complete_gpu_task_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;


    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 0:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64((*(this->success)));
                this->__isset.success = true;
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

    return xfer;
}

int64_t JobTrackerClient::register_task_tracker(const int64_t node_id, const std::string& node_name, const int64_t storage_weight) {
    send_register_task_tracker(node_id, node_name, storage_weight);
    return recv_register_task_tracker();
}

void JobTrackerClient::send_register_task_tracker(const int64_t node_id, const std::string& node_name, const int64_t storage_weight) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("register_task_tracker", ::apache::thrift::protocol::T_CALL, cseqid);

    JobTracker_register_task_tracker_pargs args;
    args.node_id = &node_id;
    args.node_name = &node_name;
    args.storage_weight = &storage_weight;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

int64_t JobTrackerClient::recv_register_task_tracker() {

    int32_t rseqid = 0;
    std::string fname;
    ::apache::thrift::protocol::TMessageType mtype;

    iprot_->readMessageBegin(fname, mtype, rseqid);
    if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        throw x;
    }
    if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    if (fname.compare("register_task_tracker") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    int64_t _return;
    JobTracker_register_task_tracker_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        return _return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "register_task_tracker failed: unknown result");
}

void JobTrackerClient::get_all_task_tracker_info(std::map<int64_t, TaskTrackerInfo> & _return) {
    send_get_all_task_tracker_info();
    recv_get_all_task_tracker_info(_return);
}

void JobTrackerClient::send_get_all_task_tracker_info() {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("get_all_task_tracker_info", ::apache::thrift::protocol::T_CALL, cseqid);

    JobTracker_get_all_task_tracker_info_pargs args;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

void JobTrackerClient::recv_get_all_task_tracker_info(std::map<int64_t, TaskTrackerInfo> & _return) {

    int32_t rseqid = 0;
    std::string fname;
    ::apache::thrift::protocol::TMessageType mtype;

    iprot_->readMessageBegin(fname, mtype, rseqid);
    if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        throw x;
    }
    if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    if (fname.compare("get_all_task_tracker_info") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    JobTracker_get_all_task_tracker_info_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        // _return pointer has now been filled
        return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "get_all_task_tracker_info failed: unknown result");
}

void JobTrackerClient::fetch_cpu_task(TaskNode& _return, const int64_t task_tracker_id) {
    send_fetch_cpu_task(task_tracker_id);
    recv_fetch_cpu_task(_return);
}

void JobTrackerClient::send_fetch_cpu_task(const int64_t task_tracker_id) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("fetch_cpu_task", ::apache::thrift::protocol::T_CALL, cseqid);

    JobTracker_fetch_cpu_task_pargs args;
    args.task_tracker_id = &task_tracker_id;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

void JobTrackerClient::recv_fetch_cpu_task(TaskNode& _return) {

    int32_t rseqid = 0;
    std::string fname;
    ::apache::thrift::protocol::TMessageType mtype;

    iprot_->readMessageBegin(fname, mtype, rseqid);
    if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        throw x;
    }
    if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    if (fname.compare("fetch_cpu_task") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    JobTracker_fetch_cpu_task_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        // _return pointer has now been filled
        return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "fetch_cpu_task failed: unknown result");
}

void JobTrackerClient::fetch_gpu_task(TaskNode& _return, const int64_t task_tracker_id) {
    send_fetch_gpu_task(task_tracker_id);
    recv_fetch_gpu_task(_return);
}

void JobTrackerClient::send_fetch_gpu_task(const int64_t task_tracker_id) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("fetch_gpu_task", ::apache::thrift::protocol::T_CALL, cseqid);

    JobTracker_fetch_gpu_task_pargs args;
    args.task_tracker_id = &task_tracker_id;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

void JobTrackerClient::recv_fetch_gpu_task(TaskNode& _return) {

    int32_t rseqid = 0;
    std::string fname;
    ::apache::thrift::protocol::TMessageType mtype;

    iprot_->readMessageBegin(fname, mtype, rseqid);
    if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        throw x;
    }
    if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    if (fname.compare("fetch_gpu_task") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    JobTracker_fetch_gpu_task_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        // _return pointer has now been filled
        return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "fetch_gpu_task failed: unknown result");
}

int64_t JobTrackerClient::complete_cpu_task(const int64_t stage_id, const int64_t task_id) {
    send_complete_cpu_task(stage_id, task_id);
    return recv_complete_cpu_task();
}

void JobTrackerClient::send_complete_cpu_task(const int64_t stage_id, const int64_t task_id) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("complete_cpu_task", ::apache::thrift::protocol::T_CALL, cseqid);

    JobTracker_complete_cpu_task_pargs args;
    args.stage_id = &stage_id;
    args.task_id = &task_id;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

int64_t JobTrackerClient::recv_complete_cpu_task() {

    int32_t rseqid = 0;
    std::string fname;
    ::apache::thrift::protocol::TMessageType mtype;

    iprot_->readMessageBegin(fname, mtype, rseqid);
    if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        throw x;
    }
    if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    if (fname.compare("complete_cpu_task") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    int64_t _return;
    JobTracker_complete_cpu_task_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        return _return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "complete_cpu_task failed: unknown result");
}

int64_t JobTrackerClient::complete_gpu_task(const int64_t stage_id, const int64_t task_id) {
    send_complete_gpu_task(stage_id, task_id);
    return recv_complete_gpu_task();
}

void JobTrackerClient::send_complete_gpu_task(const int64_t stage_id, const int64_t task_id) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("complete_gpu_task", ::apache::thrift::protocol::T_CALL, cseqid);

    JobTracker_complete_gpu_task_pargs args;
    args.stage_id = &stage_id;
    args.task_id = &task_id;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

int64_t JobTrackerClient::recv_complete_gpu_task() {

    int32_t rseqid = 0;
    std::string fname;
    ::apache::thrift::protocol::TMessageType mtype;

    iprot_->readMessageBegin(fname, mtype, rseqid);
    if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        throw x;
    }
    if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    if (fname.compare("complete_gpu_task") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    int64_t _return;
    JobTracker_complete_gpu_task_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        return _return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "complete_gpu_task failed: unknown result");
}

bool JobTrackerProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
    ProcessMap::iterator pfn;
    pfn = processMap_.find(fname);
    if (pfn == processMap_.end()) {
        iprot->skip(::apache::thrift::protocol::T_STRUCT);
        iprot->readMessageEnd();
        iprot->getTransport()->readEnd();
        ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
        oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return true;
    }
    (this->*(pfn->second))(seqid, iprot, oprot, callContext);
    return true;
}

void JobTrackerProcessor::process_register_task_tracker(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("JobTracker.register_task_tracker", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "JobTracker.register_task_tracker");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "JobTracker.register_task_tracker");
    }

    JobTracker_register_task_tracker_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "JobTracker.register_task_tracker", bytes);
    }

    JobTracker_register_task_tracker_result result;
    try {
        result.success = iface_->register_task_tracker(args.node_id, args.node_name, args.storage_weight);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "JobTracker.register_task_tracker");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("register_task_tracker", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "JobTracker.register_task_tracker");
    }

    oprot->writeMessageBegin("register_task_tracker", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "JobTracker.register_task_tracker", bytes);
    }
}

void JobTrackerProcessor::process_get_all_task_tracker_info(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("JobTracker.get_all_task_tracker_info", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "JobTracker.get_all_task_tracker_info");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "JobTracker.get_all_task_tracker_info");
    }

    JobTracker_get_all_task_tracker_info_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "JobTracker.get_all_task_tracker_info", bytes);
    }

    JobTracker_get_all_task_tracker_info_result result;
    try {
        iface_->get_all_task_tracker_info(result.success);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "JobTracker.get_all_task_tracker_info");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("get_all_task_tracker_info", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "JobTracker.get_all_task_tracker_info");
    }

    oprot->writeMessageBegin("get_all_task_tracker_info", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "JobTracker.get_all_task_tracker_info", bytes);
    }
}

void JobTrackerProcessor::process_fetch_cpu_task(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("JobTracker.fetch_cpu_task", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "JobTracker.fetch_cpu_task");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "JobTracker.fetch_cpu_task");
    }

    JobTracker_fetch_cpu_task_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "JobTracker.fetch_cpu_task", bytes);
    }

    JobTracker_fetch_cpu_task_result result;
    try {
        iface_->fetch_cpu_task(result.success, args.task_tracker_id);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "JobTracker.fetch_cpu_task");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("fetch_cpu_task", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "JobTracker.fetch_cpu_task");
    }

    oprot->writeMessageBegin("fetch_cpu_task", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "JobTracker.fetch_cpu_task", bytes);
    }
}

void JobTrackerProcessor::process_fetch_gpu_task(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("JobTracker.fetch_gpu_task", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "JobTracker.fetch_gpu_task");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "JobTracker.fetch_gpu_task");
    }

    JobTracker_fetch_gpu_task_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "JobTracker.fetch_gpu_task", bytes);
    }

    JobTracker_fetch_gpu_task_result result;
    try {
        iface_->fetch_gpu_task(result.success, args.task_tracker_id);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "JobTracker.fetch_gpu_task");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("fetch_gpu_task", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "JobTracker.fetch_gpu_task");
    }

    oprot->writeMessageBegin("fetch_gpu_task", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "JobTracker.fetch_gpu_task", bytes);
    }
}

void JobTrackerProcessor::process_complete_cpu_task(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("JobTracker.complete_cpu_task", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "JobTracker.complete_cpu_task");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "JobTracker.complete_cpu_task");
    }

    JobTracker_complete_cpu_task_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "JobTracker.complete_cpu_task", bytes);
    }

    JobTracker_complete_cpu_task_result result;
    try {
        result.success = iface_->complete_cpu_task(args.stage_id, args.task_id);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "JobTracker.complete_cpu_task");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("complete_cpu_task", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "JobTracker.complete_cpu_task");
    }

    oprot->writeMessageBegin("complete_cpu_task", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "JobTracker.complete_cpu_task", bytes);
    }
}

void JobTrackerProcessor::process_complete_gpu_task(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("JobTracker.complete_gpu_task", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "JobTracker.complete_gpu_task");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "JobTracker.complete_gpu_task");
    }

    JobTracker_complete_gpu_task_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "JobTracker.complete_gpu_task", bytes);
    }

    JobTracker_complete_gpu_task_result result;
    try {
        result.success = iface_->complete_gpu_task(args.stage_id, args.task_id);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "JobTracker.complete_gpu_task");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("complete_gpu_task", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "JobTracker.complete_gpu_task");
    }

    oprot->writeMessageBegin("complete_gpu_task", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "JobTracker.complete_gpu_task", bytes);
    }
}

::boost::shared_ptr< ::apache::thrift::TProcessor > JobTrackerProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
    ::apache::thrift::ReleaseHandler< JobTrackerIfFactory > cleanup(handlerFactory_);
    ::boost::shared_ptr< JobTrackerIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
    ::boost::shared_ptr< ::apache::thrift::TProcessor > processor(new JobTrackerProcessor(handler));
    return processor;
}
}
} // namespace

