#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_monotonic_stack_histogram;
    std::vector<long long> b_bars = {6, 2, 5, 4, 5, 1, 6};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += largest_histogram_area(b_bars);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "monotonic_stack_histogram us=" << us << " sink=" << sink << "\n";
    return 0;
}
