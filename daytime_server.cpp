#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <vector>

using boost::asio::ip::tcp;

void print(const boost::system::error_code & e) {
     std::cout << "hello, world" << std::endl;
}

std::string make_daytime_string()
{
  using namespace std; // For time_t, time and ctime;
  time_t now = time(0);
  return ctime(&now);
}

int main() {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(boost::asio::ip::tcp::v4(), 1313));

    try {
        for(;;) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            std::string message = make_daytime_string();
            std::cout << message << std::endl;

            boost::system::error_code ignore_error;
            boost::asio::write(socket, boost::asio::buffer(message), ignore_error);
        }
    } catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}