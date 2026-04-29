#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <vector>

void print(const boost::system::error_code & e) {
     std::cout << "hello, world" << std::endl;
}


int main() {
    boost::asio::io_context io_context;

    boost::asio::steady_timer t(io_context, boost::asio::chrono::seconds(2));
    t.async_wait(print);

    io_context.run();

    return 0;
}