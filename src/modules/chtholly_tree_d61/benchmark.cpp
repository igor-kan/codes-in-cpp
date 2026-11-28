#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_chtholly_tree_d61;
    ChthollyTree ct(64);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        ct.assign(iter % 40, (iter % 40) + 20, static_cast<std::int64_t>(iter % 9));
    sink = sink + ct.range_sum(0, 63);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "chtholly_tree_d61 us=" << us << " sink=" << sink << "\n";
    return 0;
}
