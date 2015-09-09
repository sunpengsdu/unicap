// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "./job_tracker_function.h"

using namespace  ::ntu::cap;

int main(int argc, char **argv) {
    //google::InitGoogleLogging(argv[0]);

    std::thread server_side_thread;
    server_side_thread = start_job_tracker(10);

    KeyPartition rrr;
    rrr.__set_partition_algo(KeyPartitionAlgo::HashingPartition);
    create_table("a", 10, rrr);
    create_cf("a", "a", StorageType::InMemoryKeyValue);



    auto i =  NodeInfo::singleton()._client_task_tracker[0];
    i->open_transport();
    std::vector<std::string> row;
    std::vector<std::string> column;
    std::vector<std::string> value;
    row.push_back("a");
    row.push_back("b");
    column.push_back("1");
    column.push_back("2");
    value.push_back("a1");
    value.push_back("b2");
    i->method()->vector_put("a", 0, "a",row, column, value);
    i->close_transport();

    std::vector<std::string> return_value1;
    i->open_transport();
    i->method()->vector_get(return_value1, "a", 0, "a", row, column);
    i->close_transport();

    for (int j=0; j<return_value1.size(); ++j) {
        std::cout << return_value1[j] << "\n";
    }


    std::vector<std::vector<std::string> > return_value2;
    i->open_transport();
    i->method()->scan_all(return_value2, "a", 0, "a");
    i->close_transport();

    for (int j=0; j<return_value2[0].size(); ++j) {
        std::cout << return_value2[0][j] << ":"
                  << return_value2[1][j] << "->"
                  << return_value2[2][j] << "\n";
    }




// create_cf("a", "b", StorageType::CommonKeyValue);


// create_task()


// foo.compare_exchange_weak(&i, j, std::memory_order_release, std::memory_order_release);

// std::atomic::compare_exchange_weak(std::ref(0), 1, std::memory_order_release, std::memory_order_release);

    server_side_thread.join();
    return 0;
}
