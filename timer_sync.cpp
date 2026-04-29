#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <vector>

int main() {
    boost::asio::io_context io_context;

    boost::asio::steady_timer t(io_context, boost::asio::chrono::milliseconds(100));
    t.wait();


    std::cout << "hello, world" << std::endl;
    return 0;
}