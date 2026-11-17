#include "interface.hpp"
#include <chrono>
#include <iostream>


int main() {
    using namespace codes_fenwick_range_add_cpp;
    DualFenwick df(256);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        df.range_add(iter % 64, 128 + (iter % 64), 3); sink += df.range_sum(0, 255);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "fenwick_range_add_cpp us=" << us << " sink=" << sink << "\n";
    return 0;
}
