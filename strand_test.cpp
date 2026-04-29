#include <boost/asio.hpp>
#include <iostream>
#include <thread>

using namespace boost::asio;




void tet_strand1() {

    io_context io;

    auto strand = make_strand(io);

    for (int i = 0; i < 10; ++i) {
        post(strand, [=] {
            std::cout << "start " << i
                      << " thread " << std::this_thread::get_id()
                      << std::endl;

            std::this_thread::sleep_for(std::chrono::microseconds(1));

            std::cout << "end   " << i << std::endl;
        });
    }

    std::thread t1([&]{ io.run(); });
    std::thread t2([&]{ io.run(); });

    t1.join();
    t2.join();
}

void tet_strand2() {
     io_context io;

    int a = 0;

    auto strand1 = make_strand(io);
    auto strand2 = make_strand(io);

    for (int i = 0; i < 100000; ++i) {
        post(strand1, [&] {
            // std::cout << "start " << i
            //           << " thread " << std::this_thread::get_id()
            //           << std::endl;

            // std::this_thread::sleep_for(std::chrono::microseconds(1));
            a++;

            // std::cout << "end   " << i << std::endl;
        });

        post(strand1, [&] {
            // std::cout << "start " << i
            //           << " thread " << std::this_thread::get_id()
            //           << std::endl;

            // std::this_thread::sleep_for(std::chrono::microseconds(1));
            a++;

            // std::cout << "end   " << i << std::endl;
        });
    }

    std::thread t1([&]{ io.run(); });
    std::thread t2([&]{ io.run(); });

    t1.join();
    t2.join();

    std:: cout << a << std::endl;
}

int main() {
    tet_strand1();
    return 0;
}