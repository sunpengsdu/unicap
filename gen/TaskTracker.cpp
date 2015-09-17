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
#include "TaskTracker.h"

namespace ntu {
namespace cap {


TaskTracker_ping_args::~TaskTracker_ping_args() throw() {
}


uint32_t TaskTracker_ping_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t TaskTracker_ping_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_ping_args");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_ping_pargs::~TaskTracker_ping_pargs() throw() {
}


uint32_t TaskTracker_ping_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_ping_pargs");

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_ping_result::~TaskTracker_ping_result() throw() {
}


uint32_t TaskTracker_ping_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->success);
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

uint32_t TaskTracker_ping_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("TaskTracker_ping_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
        xfer += oprot->writeString(this->success);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


TaskTracker_ping_presult::~TaskTracker_ping_presult() throw() {
}


uint32_t TaskTracker_ping_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString((*(this->success)));
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


TaskTracker_create_table_args::~TaskTracker_create_table_args() throw() {
}


uint32_t TaskTracker_create_table_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                xfer += this->table_property.read(iprot);
                this->__isset.table_property = true;
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

uint32_t TaskTracker_create_table_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_create_table_args");

    xfer += oprot->writeFieldBegin("table_property", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->table_property.write(oprot);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_create_table_pargs::~TaskTracker_create_table_pargs() throw() {
}


uint32_t TaskTracker_create_table_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_create_table_pargs");

    xfer += oprot->writeFieldBegin("table_property", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += (*(this->table_property)).write(oprot);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_create_table_result::~TaskTracker_create_table_result() throw() {
}


uint32_t TaskTracker_create_table_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t TaskTracker_create_table_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("TaskTracker_create_table_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
        xfer += oprot->writeI64(this->success);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


TaskTracker_create_table_presult::~TaskTracker_create_table_presult() throw() {
}


uint32_t TaskTracker_create_table_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


TaskTracker_create_cf_args::~TaskTracker_create_cf_args() throw() {
}


uint32_t TaskTracker_create_cf_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->table_name);
                this->__isset.table_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                xfer += this->cf_property.read(iprot);
                this->__isset.cf_property = true;
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

uint32_t TaskTracker_create_cf_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_create_cf_args");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->table_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_property", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->cf_property.write(oprot);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_create_cf_pargs::~TaskTracker_create_cf_pargs() throw() {
}


uint32_t TaskTracker_create_cf_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_create_cf_pargs");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString((*(this->table_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_property", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += (*(this->cf_property)).write(oprot);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_create_cf_result::~TaskTracker_create_cf_result() throw() {
}


uint32_t TaskTracker_create_cf_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t TaskTracker_create_cf_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("TaskTracker_create_cf_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
        xfer += oprot->writeI64(this->success);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


TaskTracker_create_cf_presult::~TaskTracker_create_cf_presult() throw() {
}


uint32_t TaskTracker_create_cf_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


TaskTracker_vector_put_args::~TaskTracker_vector_put_args() throw() {
}


uint32_t TaskTracker_vector_put_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->table_name);
                this->__isset.table_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->shard_id);
                this->__isset.shard_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 3:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->cf_name);
                this->__isset.cf_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 4:
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->row_key.clear();
                    uint32_t _size57;
                    ::apache::thrift::protocol::TType _etype60;
                    xfer += iprot->readListBegin(_etype60, _size57);
                    this->row_key.resize(_size57);
                    uint32_t _i61;
                    for (_i61 = 0; _i61 < _size57; ++_i61) {
                        xfer += iprot->readString(this->row_key[_i61]);
                    }
                    xfer += iprot->readListEnd();
                }
                this->__isset.row_key = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 5:
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->column_key.clear();
                    uint32_t _size62;
                    ::apache::thrift::protocol::TType _etype65;
                    xfer += iprot->readListBegin(_etype65, _size62);
                    this->column_key.resize(_size62);
                    uint32_t _i66;
                    for (_i66 = 0; _i66 < _size62; ++_i66) {
                        xfer += iprot->readString(this->column_key[_i66]);
                    }
                    xfer += iprot->readListEnd();
                }
                this->__isset.column_key = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 6:
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->value.clear();
                    uint32_t _size67;
                    ::apache::thrift::protocol::TType _etype70;
                    xfer += iprot->readListBegin(_etype70, _size67);
                    this->value.resize(_size67);
                    uint32_t _i71;
                    for (_i71 = 0; _i71 < _size67; ++_i71) {
                        xfer += iprot->readString(this->value[_i71]);
                    }
                    xfer += iprot->readListEnd();
                }
                this->__isset.value = true;
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

uint32_t TaskTracker_vector_put_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_vector_put_args");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->table_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->shard_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->cf_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("row_key", ::apache::thrift::protocol::T_LIST, 4);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->row_key.size()));
        std::vector<std::string> ::const_iterator _iter72;
        for (_iter72 = this->row_key.begin(); _iter72 != this->row_key.end(); ++_iter72) {
            xfer += oprot->writeString((*_iter72));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("column_key", ::apache::thrift::protocol::T_LIST, 5);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->column_key.size()));
        std::vector<std::string> ::const_iterator _iter73;
        for (_iter73 = this->column_key.begin(); _iter73 != this->column_key.end(); ++_iter73) {
            xfer += oprot->writeString((*_iter73));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_LIST, 6);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->value.size()));
        std::vector<std::string> ::const_iterator _iter74;
        for (_iter74 = this->value.begin(); _iter74 != this->value.end(); ++_iter74) {
            xfer += oprot->writeString((*_iter74));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_vector_put_pargs::~TaskTracker_vector_put_pargs() throw() {
}


uint32_t TaskTracker_vector_put_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_vector_put_pargs");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString((*(this->table_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64((*(this->shard_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString((*(this->cf_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("row_key", ::apache::thrift::protocol::T_LIST, 4);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->row_key)).size()));
        std::vector<std::string> ::const_iterator _iter75;
        for (_iter75 = (*(this->row_key)).begin(); _iter75 != (*(this->row_key)).end(); ++_iter75) {
            xfer += oprot->writeString((*_iter75));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("column_key", ::apache::thrift::protocol::T_LIST, 5);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->column_key)).size()));
        std::vector<std::string> ::const_iterator _iter76;
        for (_iter76 = (*(this->column_key)).begin(); _iter76 != (*(this->column_key)).end(); ++_iter76) {
            xfer += oprot->writeString((*_iter76));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_LIST, 6);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->value)).size()));
        std::vector<std::string> ::const_iterator _iter77;
        for (_iter77 = (*(this->value)).begin(); _iter77 != (*(this->value)).end(); ++_iter77) {
            xfer += oprot->writeString((*_iter77));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_vector_put_result::~TaskTracker_vector_put_result() throw() {
}


uint32_t TaskTracker_vector_put_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t TaskTracker_vector_put_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("TaskTracker_vector_put_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
        xfer += oprot->writeI64(this->success);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


TaskTracker_vector_put_presult::~TaskTracker_vector_put_presult() throw() {
}


uint32_t TaskTracker_vector_put_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


TaskTracker_timely_vector_put_args::~TaskTracker_timely_vector_put_args() throw() {
}


uint32_t TaskTracker_timely_vector_put_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->table_name);
                this->__isset.table_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->shard_id);
                this->__isset.shard_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 3:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->cf_name);
                this->__isset.cf_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 4:
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->row_key.clear();
                    uint32_t _size78;
                    ::apache::thrift::protocol::TType _etype81;
                    xfer += iprot->readListBegin(_etype81, _size78);
                    this->row_key.resize(_size78);
                    uint32_t _i82;
                    for (_i82 = 0; _i82 < _size78; ++_i82) {
                        xfer += iprot->readString(this->row_key[_i82]);
                    }
                    xfer += iprot->readListEnd();
                }
                this->__isset.row_key = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 5:
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->column_key.clear();
                    uint32_t _size83;
                    ::apache::thrift::protocol::TType _etype86;
                    xfer += iprot->readListBegin(_etype86, _size83);
                    this->column_key.resize(_size83);
                    uint32_t _i87;
                    for (_i87 = 0; _i87 < _size83; ++_i87) {
                        xfer += iprot->readString(this->column_key[_i87]);
                    }
                    xfer += iprot->readListEnd();
                }
                this->__isset.column_key = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 6:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->time_stampe);
                this->__isset.time_stampe = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 7:
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->value.clear();
                    uint32_t _size88;
                    ::apache::thrift::protocol::TType _etype91;
                    xfer += iprot->readListBegin(_etype91, _size88);
                    this->value.resize(_size88);
                    uint32_t _i92;
                    for (_i92 = 0; _i92 < _size88; ++_i92) {
                        xfer += iprot->readString(this->value[_i92]);
                    }
                    xfer += iprot->readListEnd();
                }
                this->__isset.value = true;
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

uint32_t TaskTracker_timely_vector_put_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_timely_vector_put_args");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->table_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->shard_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->cf_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("row_key", ::apache::thrift::protocol::T_LIST, 4);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->row_key.size()));
        std::vector<std::string> ::const_iterator _iter93;
        for (_iter93 = this->row_key.begin(); _iter93 != this->row_key.end(); ++_iter93) {
            xfer += oprot->writeString((*_iter93));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("column_key", ::apache::thrift::protocol::T_LIST, 5);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->column_key.size()));
        std::vector<std::string> ::const_iterator _iter94;
        for (_iter94 = this->column_key.begin(); _iter94 != this->column_key.end(); ++_iter94) {
            xfer += oprot->writeString((*_iter94));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("time_stampe", ::apache::thrift::protocol::T_I64, 6);
    xfer += oprot->writeI64(this->time_stampe);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_LIST, 7);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->value.size()));
        std::vector<std::string> ::const_iterator _iter95;
        for (_iter95 = this->value.begin(); _iter95 != this->value.end(); ++_iter95) {
            xfer += oprot->writeString((*_iter95));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_timely_vector_put_pargs::~TaskTracker_timely_vector_put_pargs() throw() {
}


uint32_t TaskTracker_timely_vector_put_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_timely_vector_put_pargs");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString((*(this->table_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64((*(this->shard_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString((*(this->cf_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("row_key", ::apache::thrift::protocol::T_LIST, 4);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->row_key)).size()));
        std::vector<std::string> ::const_iterator _iter96;
        for (_iter96 = (*(this->row_key)).begin(); _iter96 != (*(this->row_key)).end(); ++_iter96) {
            xfer += oprot->writeString((*_iter96));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("column_key", ::apache::thrift::protocol::T_LIST, 5);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->column_key)).size()));
        std::vector<std::string> ::const_iterator _iter97;
        for (_iter97 = (*(this->column_key)).begin(); _iter97 != (*(this->column_key)).end(); ++_iter97) {
            xfer += oprot->writeString((*_iter97));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("time_stampe", ::apache::thrift::protocol::T_I64, 6);
    xfer += oprot->writeI64((*(this->time_stampe)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_LIST, 7);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->value)).size()));
        std::vector<std::string> ::const_iterator _iter98;
        for (_iter98 = (*(this->value)).begin(); _iter98 != (*(this->value)).end(); ++_iter98) {
            xfer += oprot->writeString((*_iter98));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_timely_vector_put_result::~TaskTracker_timely_vector_put_result() throw() {
}


uint32_t TaskTracker_timely_vector_put_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t TaskTracker_timely_vector_put_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("TaskTracker_timely_vector_put_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
        xfer += oprot->writeI64(this->success);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


TaskTracker_timely_vector_put_presult::~TaskTracker_timely_vector_put_presult() throw() {
}


uint32_t TaskTracker_timely_vector_put_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


TaskTracker_vector_get_args::~TaskTracker_vector_get_args() throw() {
}


uint32_t TaskTracker_vector_get_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->table_name);
                this->__isset.table_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->shard_id);
                this->__isset.shard_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 3:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->cf_name);
                this->__isset.cf_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 4:
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->row_key.clear();
                    uint32_t _size99;
                    ::apache::thrift::protocol::TType _etype102;
                    xfer += iprot->readListBegin(_etype102, _size99);
                    this->row_key.resize(_size99);
                    uint32_t _i103;
                    for (_i103 = 0; _i103 < _size99; ++_i103) {
                        xfer += iprot->readString(this->row_key[_i103]);
                    }
                    xfer += iprot->readListEnd();
                }
                this->__isset.row_key = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 5:
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->column_key.clear();
                    uint32_t _size104;
                    ::apache::thrift::protocol::TType _etype107;
                    xfer += iprot->readListBegin(_etype107, _size104);
                    this->column_key.resize(_size104);
                    uint32_t _i108;
                    for (_i108 = 0; _i108 < _size104; ++_i108) {
                        xfer += iprot->readString(this->column_key[_i108]);
                    }
                    xfer += iprot->readListEnd();
                }
                this->__isset.column_key = true;
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

uint32_t TaskTracker_vector_get_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_vector_get_args");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->table_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->shard_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->cf_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("row_key", ::apache::thrift::protocol::T_LIST, 4);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->row_key.size()));
        std::vector<std::string> ::const_iterator _iter109;
        for (_iter109 = this->row_key.begin(); _iter109 != this->row_key.end(); ++_iter109) {
            xfer += oprot->writeString((*_iter109));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("column_key", ::apache::thrift::protocol::T_LIST, 5);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->column_key.size()));
        std::vector<std::string> ::const_iterator _iter110;
        for (_iter110 = this->column_key.begin(); _iter110 != this->column_key.end(); ++_iter110) {
            xfer += oprot->writeString((*_iter110));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_vector_get_pargs::~TaskTracker_vector_get_pargs() throw() {
}


uint32_t TaskTracker_vector_get_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_vector_get_pargs");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString((*(this->table_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64((*(this->shard_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString((*(this->cf_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("row_key", ::apache::thrift::protocol::T_LIST, 4);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->row_key)).size()));
        std::vector<std::string> ::const_iterator _iter111;
        for (_iter111 = (*(this->row_key)).begin(); _iter111 != (*(this->row_key)).end(); ++_iter111) {
            xfer += oprot->writeString((*_iter111));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("column_key", ::apache::thrift::protocol::T_LIST, 5);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->column_key)).size()));
        std::vector<std::string> ::const_iterator _iter112;
        for (_iter112 = (*(this->column_key)).begin(); _iter112 != (*(this->column_key)).end(); ++_iter112) {
            xfer += oprot->writeString((*_iter112));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_vector_get_result::~TaskTracker_vector_get_result() throw() {
}


uint32_t TaskTracker_vector_get_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->success.clear();
                    uint32_t _size113;
                    ::apache::thrift::protocol::TType _etype116;
                    xfer += iprot->readListBegin(_etype116, _size113);
                    this->success.resize(_size113);
                    uint32_t _i117;
                    for (_i117 = 0; _i117 < _size113; ++_i117) {
                        xfer += iprot->readString(this->success[_i117]);
                    }
                    xfer += iprot->readListEnd();
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

uint32_t TaskTracker_vector_get_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("TaskTracker_vector_get_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
        {
            xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->success.size()));
            std::vector<std::string> ::const_iterator _iter118;
            for (_iter118 = this->success.begin(); _iter118 != this->success.end(); ++_iter118) {
                xfer += oprot->writeString((*_iter118));
            }
            xfer += oprot->writeListEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


TaskTracker_vector_get_presult::~TaskTracker_vector_get_presult() throw() {
}


uint32_t TaskTracker_vector_get_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    (*(this->success)).clear();
                    uint32_t _size119;
                    ::apache::thrift::protocol::TType _etype122;
                    xfer += iprot->readListBegin(_etype122, _size119);
                    (*(this->success)).resize(_size119);
                    uint32_t _i123;
                    for (_i123 = 0; _i123 < _size119; ++_i123) {
                        xfer += iprot->readString((*(this->success))[_i123]);
                    }
                    xfer += iprot->readListEnd();
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


TaskTracker_scan_all_args::~TaskTracker_scan_all_args() throw() {
}


uint32_t TaskTracker_scan_all_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->table_name);
                this->__isset.table_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->shard_id);
                this->__isset.shard_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 3:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->cf_name);
                this->__isset.cf_name = true;
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

uint32_t TaskTracker_scan_all_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_scan_all_args");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->table_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->shard_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->cf_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_scan_all_pargs::~TaskTracker_scan_all_pargs() throw() {
}


uint32_t TaskTracker_scan_all_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_scan_all_pargs");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString((*(this->table_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64((*(this->shard_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString((*(this->cf_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_scan_all_result::~TaskTracker_scan_all_result() throw() {
}


uint32_t TaskTracker_scan_all_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->success.clear();
                    uint32_t _size124;
                    ::apache::thrift::protocol::TType _etype127;
                    xfer += iprot->readListBegin(_etype127, _size124);
                    this->success.resize(_size124);
                    uint32_t _i128;
                    for (_i128 = 0; _i128 < _size124; ++_i128) {
                        {
                            this->success[_i128].clear();
                            uint32_t _size129;
                            ::apache::thrift::protocol::TType _etype132;
                            xfer += iprot->readListBegin(_etype132, _size129);
                            this->success[_i128].resize(_size129);
                            uint32_t _i133;
                            for (_i133 = 0; _i133 < _size129; ++_i133) {
                                xfer += iprot->readString(this->success[_i128][_i133]);
                            }
                            xfer += iprot->readListEnd();
                        }
                    }
                    xfer += iprot->readListEnd();
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

uint32_t TaskTracker_scan_all_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("TaskTracker_scan_all_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
        {
            xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->success.size()));
            std::vector<std::vector<std::string> > ::const_iterator _iter134;
            for (_iter134 = this->success.begin(); _iter134 != this->success.end(); ++_iter134) {
                {
                    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter134).size()));
                    std::vector<std::string> ::const_iterator _iter135;
                    for (_iter135 = (*_iter134).begin(); _iter135 != (*_iter134).end(); ++_iter135) {
                        xfer += oprot->writeString((*_iter135));
                    }
                    xfer += oprot->writeListEnd();
                }
            }
            xfer += oprot->writeListEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


TaskTracker_scan_all_presult::~TaskTracker_scan_all_presult() throw() {
}


uint32_t TaskTracker_scan_all_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    (*(this->success)).clear();
                    uint32_t _size136;
                    ::apache::thrift::protocol::TType _etype139;
                    xfer += iprot->readListBegin(_etype139, _size136);
                    (*(this->success)).resize(_size136);
                    uint32_t _i140;
                    for (_i140 = 0; _i140 < _size136; ++_i140) {
                        {
                            (*(this->success))[_i140].clear();
                            uint32_t _size141;
                            ::apache::thrift::protocol::TType _etype144;
                            xfer += iprot->readListBegin(_etype144, _size141);
                            (*(this->success))[_i140].resize(_size141);
                            uint32_t _i145;
                            for (_i145 = 0; _i145 < _size141; ++_i145) {
                                xfer += iprot->readString((*(this->success))[_i140][_i145]);
                            }
                            xfer += iprot->readListEnd();
                        }
                    }
                    xfer += iprot->readListEnd();
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


TaskTracker_scan_by_time_args::~TaskTracker_scan_by_time_args() throw() {
}


uint32_t TaskTracker_scan_by_time_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->table_name);
                this->__isset.table_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->shard_id);
                this->__isset.shard_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 3:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->cf_name);
                this->__isset.cf_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 4:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->time_stamp);
                this->__isset.time_stamp = true;
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

uint32_t TaskTracker_scan_by_time_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_scan_by_time_args");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->table_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->shard_id);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->cf_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("time_stamp", ::apache::thrift::protocol::T_I64, 4);
    xfer += oprot->writeI64(this->time_stamp);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_scan_by_time_pargs::~TaskTracker_scan_by_time_pargs() throw() {
}


uint32_t TaskTracker_scan_by_time_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTracker_scan_by_time_pargs");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString((*(this->table_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_id", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64((*(this->shard_id)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString((*(this->cf_name)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("time_stamp", ::apache::thrift::protocol::T_I64, 4);
    xfer += oprot->writeI64((*(this->time_stamp)));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}


TaskTracker_scan_by_time_result::~TaskTracker_scan_by_time_result() throw() {
}


uint32_t TaskTracker_scan_by_time_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->success.clear();
                    uint32_t _size146;
                    ::apache::thrift::protocol::TType _etype149;
                    xfer += iprot->readListBegin(_etype149, _size146);
                    this->success.resize(_size146);
                    uint32_t _i150;
                    for (_i150 = 0; _i150 < _size146; ++_i150) {
                        {
                            this->success[_i150].clear();
                            uint32_t _size151;
                            ::apache::thrift::protocol::TType _etype154;
                            xfer += iprot->readListBegin(_etype154, _size151);
                            this->success[_i150].resize(_size151);
                            uint32_t _i155;
                            for (_i155 = 0; _i155 < _size151; ++_i155) {
                                xfer += iprot->readString(this->success[_i150][_i155]);
                            }
                            xfer += iprot->readListEnd();
                        }
                    }
                    xfer += iprot->readListEnd();
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

uint32_t TaskTracker_scan_by_time_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

    uint32_t xfer = 0;

    xfer += oprot->writeStructBegin("TaskTracker_scan_by_time_result");

    if (this->__isset.success) {
        xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
        {
            xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->success.size()));
            std::vector<std::vector<std::string> > ::const_iterator _iter156;
            for (_iter156 = this->success.begin(); _iter156 != this->success.end(); ++_iter156) {
                {
                    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter156).size()));
                    std::vector<std::string> ::const_iterator _iter157;
                    for (_iter157 = (*_iter156).begin(); _iter157 != (*_iter156).end(); ++_iter157) {
                        xfer += oprot->writeString((*_iter157));
                    }
                    xfer += oprot->writeListEnd();
                }
            }
            xfer += oprot->writeListEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    return xfer;
}


TaskTracker_scan_by_time_presult::~TaskTracker_scan_by_time_presult() throw() {
}


uint32_t TaskTracker_scan_by_time_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    (*(this->success)).clear();
                    uint32_t _size158;
                    ::apache::thrift::protocol::TType _etype161;
                    xfer += iprot->readListBegin(_etype161, _size158);
                    (*(this->success)).resize(_size158);
                    uint32_t _i162;
                    for (_i162 = 0; _i162 < _size158; ++_i162) {
                        {
                            (*(this->success))[_i162].clear();
                            uint32_t _size163;
                            ::apache::thrift::protocol::TType _etype166;
                            xfer += iprot->readListBegin(_etype166, _size163);
                            (*(this->success))[_i162].resize(_size163);
                            uint32_t _i167;
                            for (_i167 = 0; _i167 < _size163; ++_i167) {
                                xfer += iprot->readString((*(this->success))[_i162][_i167]);
                            }
                            xfer += iprot->readListEnd();
                        }
                    }
                    xfer += iprot->readListEnd();
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

void TaskTrackerClient::ping(std::string& _return) {
    send_ping();
    recv_ping(_return);
}

void TaskTrackerClient::send_ping() {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("ping", ::apache::thrift::protocol::T_CALL, cseqid);

    TaskTracker_ping_pargs args;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

void TaskTrackerClient::recv_ping(std::string& _return) {

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
    if (fname.compare("ping") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    TaskTracker_ping_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        // _return pointer has now been filled
        return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "ping failed: unknown result");
}

int64_t TaskTrackerClient::create_table(const TableProperty& table_property) {
    send_create_table(table_property);
    return recv_create_table();
}

void TaskTrackerClient::send_create_table(const TableProperty& table_property) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("create_table", ::apache::thrift::protocol::T_CALL, cseqid);

    TaskTracker_create_table_pargs args;
    args.table_property = &table_property;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

int64_t TaskTrackerClient::recv_create_table() {

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
    if (fname.compare("create_table") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    int64_t _return;
    TaskTracker_create_table_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        return _return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "create_table failed: unknown result");
}

int64_t TaskTrackerClient::create_cf(const std::string& table_name, const ColumnFamilyProperty& cf_property) {
    send_create_cf(table_name, cf_property);
    return recv_create_cf();
}

void TaskTrackerClient::send_create_cf(const std::string& table_name, const ColumnFamilyProperty& cf_property) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("create_cf", ::apache::thrift::protocol::T_CALL, cseqid);

    TaskTracker_create_cf_pargs args;
    args.table_name = &table_name;
    args.cf_property = &cf_property;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

int64_t TaskTrackerClient::recv_create_cf() {

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
    if (fname.compare("create_cf") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    int64_t _return;
    TaskTracker_create_cf_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        return _return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "create_cf failed: unknown result");
}

int64_t TaskTrackerClient::vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const std::vector<std::string> & value) {
    send_vector_put(table_name, shard_id, cf_name, row_key, column_key, value);
    return recv_vector_put();
}

void TaskTrackerClient::send_vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const std::vector<std::string> & value) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("vector_put", ::apache::thrift::protocol::T_CALL, cseqid);

    TaskTracker_vector_put_pargs args;
    args.table_name = &table_name;
    args.shard_id = &shard_id;
    args.cf_name = &cf_name;
    args.row_key = &row_key;
    args.column_key = &column_key;
    args.value = &value;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

int64_t TaskTrackerClient::recv_vector_put() {

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
    if (fname.compare("vector_put") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    int64_t _return;
    TaskTracker_vector_put_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        return _return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "vector_put failed: unknown result");
}

int64_t TaskTrackerClient::timely_vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const int64_t time_stampe, const std::vector<std::string> & value) {
    send_timely_vector_put(table_name, shard_id, cf_name, row_key, column_key, time_stampe, value);
    return recv_timely_vector_put();
}

void TaskTrackerClient::send_timely_vector_put(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key, const int64_t time_stampe, const std::vector<std::string> & value) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("timely_vector_put", ::apache::thrift::protocol::T_CALL, cseqid);

    TaskTracker_timely_vector_put_pargs args;
    args.table_name = &table_name;
    args.shard_id = &shard_id;
    args.cf_name = &cf_name;
    args.row_key = &row_key;
    args.column_key = &column_key;
    args.time_stampe = &time_stampe;
    args.value = &value;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

int64_t TaskTrackerClient::recv_timely_vector_put() {

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
    if (fname.compare("timely_vector_put") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    int64_t _return;
    TaskTracker_timely_vector_put_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        return _return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "timely_vector_put failed: unknown result");
}

void TaskTrackerClient::vector_get(std::vector<std::string> & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key) {
    send_vector_get(table_name, shard_id, cf_name, row_key, column_key);
    recv_vector_get(_return);
}

void TaskTrackerClient::send_vector_get(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const std::vector<std::string> & row_key, const std::vector<std::string> & column_key) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("vector_get", ::apache::thrift::protocol::T_CALL, cseqid);

    TaskTracker_vector_get_pargs args;
    args.table_name = &table_name;
    args.shard_id = &shard_id;
    args.cf_name = &cf_name;
    args.row_key = &row_key;
    args.column_key = &column_key;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

void TaskTrackerClient::recv_vector_get(std::vector<std::string> & _return) {

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
    if (fname.compare("vector_get") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    TaskTracker_vector_get_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        // _return pointer has now been filled
        return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "vector_get failed: unknown result");
}

void TaskTrackerClient::scan_all(std::vector<std::vector<std::string> > & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name) {
    send_scan_all(table_name, shard_id, cf_name);
    recv_scan_all(_return);
}

void TaskTrackerClient::send_scan_all(const std::string& table_name, const int64_t shard_id, const std::string& cf_name) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("scan_all", ::apache::thrift::protocol::T_CALL, cseqid);

    TaskTracker_scan_all_pargs args;
    args.table_name = &table_name;
    args.shard_id = &shard_id;
    args.cf_name = &cf_name;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

void TaskTrackerClient::recv_scan_all(std::vector<std::vector<std::string> > & _return) {

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
    if (fname.compare("scan_all") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    TaskTracker_scan_all_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        // _return pointer has now been filled
        return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "scan_all failed: unknown result");
}

void TaskTrackerClient::scan_by_time(std::vector<std::vector<std::string> > & _return, const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const int64_t time_stamp) {
    send_scan_by_time(table_name, shard_id, cf_name, time_stamp);
    recv_scan_by_time(_return);
}

void TaskTrackerClient::send_scan_by_time(const std::string& table_name, const int64_t shard_id, const std::string& cf_name, const int64_t time_stamp) {
    int32_t cseqid = 0;
    oprot_->writeMessageBegin("scan_by_time", ::apache::thrift::protocol::T_CALL, cseqid);

    TaskTracker_scan_by_time_pargs args;
    args.table_name = &table_name;
    args.shard_id = &shard_id;
    args.cf_name = &cf_name;
    args.time_stamp = &time_stamp;
    args.write(oprot_);

    oprot_->writeMessageEnd();
    oprot_->getTransport()->writeEnd();
    oprot_->getTransport()->flush();
}

void TaskTrackerClient::recv_scan_by_time(std::vector<std::vector<std::string> > & _return) {

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
    if (fname.compare("scan_by_time") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
    }
    TaskTracker_scan_by_time_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
        // _return pointer has now been filled
        return;
    }
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "scan_by_time failed: unknown result");
}

bool TaskTrackerProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
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

void TaskTrackerProcessor::process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("TaskTracker.ping", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "TaskTracker.ping");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "TaskTracker.ping");
    }

    TaskTracker_ping_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "TaskTracker.ping", bytes);
    }

    TaskTracker_ping_result result;
    try {
        iface_->ping(result.success);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "TaskTracker.ping");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("ping", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "TaskTracker.ping");
    }

    oprot->writeMessageBegin("ping", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "TaskTracker.ping", bytes);
    }
}

void TaskTrackerProcessor::process_create_table(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("TaskTracker.create_table", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "TaskTracker.create_table");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "TaskTracker.create_table");
    }

    TaskTracker_create_table_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "TaskTracker.create_table", bytes);
    }

    TaskTracker_create_table_result result;
    try {
        result.success = iface_->create_table(args.table_property);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "TaskTracker.create_table");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("create_table", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "TaskTracker.create_table");
    }

    oprot->writeMessageBegin("create_table", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "TaskTracker.create_table", bytes);
    }
}

void TaskTrackerProcessor::process_create_cf(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("TaskTracker.create_cf", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "TaskTracker.create_cf");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "TaskTracker.create_cf");
    }

    TaskTracker_create_cf_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "TaskTracker.create_cf", bytes);
    }

    TaskTracker_create_cf_result result;
    try {
        result.success = iface_->create_cf(args.table_name, args.cf_property);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "TaskTracker.create_cf");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("create_cf", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "TaskTracker.create_cf");
    }

    oprot->writeMessageBegin("create_cf", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "TaskTracker.create_cf", bytes);
    }
}

void TaskTrackerProcessor::process_vector_put(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("TaskTracker.vector_put", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "TaskTracker.vector_put");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "TaskTracker.vector_put");
    }

    TaskTracker_vector_put_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "TaskTracker.vector_put", bytes);
    }

    TaskTracker_vector_put_result result;
    try {
        result.success = iface_->vector_put(args.table_name, args.shard_id, args.cf_name, args.row_key, args.column_key, args.value);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "TaskTracker.vector_put");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("vector_put", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "TaskTracker.vector_put");
    }

    oprot->writeMessageBegin("vector_put", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "TaskTracker.vector_put", bytes);
    }
}

void TaskTrackerProcessor::process_timely_vector_put(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("TaskTracker.timely_vector_put", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "TaskTracker.timely_vector_put");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "TaskTracker.timely_vector_put");
    }

    TaskTracker_timely_vector_put_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "TaskTracker.timely_vector_put", bytes);
    }

    TaskTracker_timely_vector_put_result result;
    try {
        result.success = iface_->timely_vector_put(args.table_name, args.shard_id, args.cf_name, args.row_key, args.column_key, args.time_stampe, args.value);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "TaskTracker.timely_vector_put");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("timely_vector_put", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "TaskTracker.timely_vector_put");
    }

    oprot->writeMessageBegin("timely_vector_put", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "TaskTracker.timely_vector_put", bytes);
    }
}

void TaskTrackerProcessor::process_vector_get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("TaskTracker.vector_get", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "TaskTracker.vector_get");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "TaskTracker.vector_get");
    }

    TaskTracker_vector_get_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "TaskTracker.vector_get", bytes);
    }

    TaskTracker_vector_get_result result;
    try {
        iface_->vector_get(result.success, args.table_name, args.shard_id, args.cf_name, args.row_key, args.column_key);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "TaskTracker.vector_get");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("vector_get", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "TaskTracker.vector_get");
    }

    oprot->writeMessageBegin("vector_get", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "TaskTracker.vector_get", bytes);
    }
}

void TaskTrackerProcessor::process_scan_all(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("TaskTracker.scan_all", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "TaskTracker.scan_all");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "TaskTracker.scan_all");
    }

    TaskTracker_scan_all_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "TaskTracker.scan_all", bytes);
    }

    TaskTracker_scan_all_result result;
    try {
        iface_->scan_all(result.success, args.table_name, args.shard_id, args.cf_name);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "TaskTracker.scan_all");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("scan_all", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "TaskTracker.scan_all");
    }

    oprot->writeMessageBegin("scan_all", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "TaskTracker.scan_all", bytes);
    }
}

void TaskTrackerProcessor::process_scan_by_time(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext) {
    void* ctx = NULL;
    if (this->eventHandler_.get() != NULL) {
        ctx = this->eventHandler_->getContext("TaskTracker.scan_by_time", callContext);
    }
    ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "TaskTracker.scan_by_time");

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preRead(ctx, "TaskTracker.scan_by_time");
    }

    TaskTracker_scan_by_time_args args;
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postRead(ctx, "TaskTracker.scan_by_time", bytes);
    }

    TaskTracker_scan_by_time_result result;
    try {
        iface_->scan_by_time(result.success, args.table_name, args.shard_id, args.cf_name, args.time_stamp);
        result.__isset.success = true;
    } catch (const std::exception& e) {
        if (this->eventHandler_.get() != NULL) {
            this->eventHandler_->handlerError(ctx, "TaskTracker.scan_by_time");
        }

        ::apache::thrift::TApplicationException x(e.what());
        oprot->writeMessageBegin("scan_by_time", ::apache::thrift::protocol::T_EXCEPTION, seqid);
        x.write(oprot);
        oprot->writeMessageEnd();
        oprot->getTransport()->writeEnd();
        oprot->getTransport()->flush();
        return;
    }

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->preWrite(ctx, "TaskTracker.scan_by_time");
    }

    oprot->writeMessageBegin("scan_by_time", ::apache::thrift::protocol::T_REPLY, seqid);
    result.write(oprot);
    oprot->writeMessageEnd();
    bytes = oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();

    if (this->eventHandler_.get() != NULL) {
        this->eventHandler_->postWrite(ctx, "TaskTracker.scan_by_time", bytes);
    }
}

::boost::shared_ptr< ::apache::thrift::TProcessor > TaskTrackerProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
    ::apache::thrift::ReleaseHandler< TaskTrackerIfFactory > cleanup(handlerFactory_);
    ::boost::shared_ptr< TaskTrackerIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
    ::boost::shared_ptr< ::apache::thrift::TProcessor > processor(new TaskTrackerProcessor(handler));
    return processor;
}
}
} // namespace

