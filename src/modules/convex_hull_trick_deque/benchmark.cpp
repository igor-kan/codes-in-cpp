#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_convex_hull_trick_deque;
    MonotoneCht cht; cht.add_line(3, 0); cht.add_line(1, 5);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += cht.query(1);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "convex_hull_trick_deque us=" << us << " sink=" << sink << "\n";
    return 0;
}
