#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <vector>

void print(const boost::system::error_code & e, int num) {
    std::cout << "hello, world:" << num << std::endl;
}


int main() {
    boost::asio::io_context io_context;

    int num = 10;

    boost::asio::steady_timer t(io_context, boost::asio::chrono::seconds(1));

    
    // std::bind
    // t.async_wait(std::bind(print, std::placeholders::_1, 10));


    // lambda
    t.async_wait([&](const boost::system::error_code& e) {
        std::cout << "hello, world:" << num << std::endl;
    });


    io_context.run();

    return 0;
}