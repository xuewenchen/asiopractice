#include <boost/asio.hpp>
#include <iostream>
#include <thread>

using namespace boost::asio;

int main() {
    io_context io;

    auto strand = make_strand(io);

    for (int i = 0; i < 5; ++i) {
        post(strand, [i] {
            std::cout << "start " << i
                      << " thread " << std::this_thread::get_id()
                      << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            std::cout << "end   " << i << std::endl;
        });
    }

    std::thread t1([&]{ io.run(); });
    std::thread t2([&]{ io.run(); });

    t1.join();
    t2.join();
}