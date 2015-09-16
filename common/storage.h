/*
 * storage.h
 *
 *  Created on: 15 Sep 2015
 *      Author: sunshine
 */

#ifndef UNICAP_COMMON_STORAGE_H_
#define UNICAP_COMMON_STORAGE_H_

#include "table.h"
#include "node_info.h"
#include "storage_info.h"
#include "../gen/JobTracker.h"
#include "../gen/TaskTracker.h"

namespace ntu {
namespace cap {

class Storage {
public:
    static int64_t vector_put(const std::string table,
                            const std::string cf,
                            int64_t shard_id,
                            std::vector<std::string> row_key,
                            std::vector<std::string> column_key,
                            std::vector<std::string> value);

    static int64_t timely_vector_put(const std::string table,
                            const std::string cf,
                            int64_t shard_id,
                            std::vector<std::string> row_key,
                            std::vector<std::string> column_key,
                            int64_t time_stamp,
                            std::vector<std::string> value);

    static int64_t vector_get(const std::string table,
                            const std::string cf,
                            int64_t shard_id,
                            std::vector<std::string> row_key,
                            std::vector<std::string> column_key,
                            std::vector<std::string>& value);

    static void scan_all(const std::string table,
                        const std::string cf,
                        int64_t shard_id,
                        std::vector<std::vector<std::string>>& value);

    static void scan_by_time(const std::string table,
                        const std::string cf,
                        int64_t shard_id,
                        int64_t time_stamp,
                        std::vector<std::vector<std::string>>& value);


};


}
}
#endif /* UNICAP_COMMON_STORAGE_H_ */
