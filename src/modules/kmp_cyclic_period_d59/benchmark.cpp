#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_kmp_cyclic_period_d59;
    std::string bs = "xyzxyzxyzxyz";
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += shortest_exact_period(bs);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "kmp_cyclic_period_d59 us=" << us << " sink=" << sink << "\n";
    return 0;
}
