#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_segment_lazy_mul_add_d61;
    std::vector<std::int64_t> a(32, 1);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        LazyMulAddTree seg(a);
    seg.range_mul(0, 15, 2);
    seg.range_add(0, 31, 1);
    sink = sink + seg.range_sum(0, 31);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "segment_lazy_mul_add_d61 us=" << us << " sink=" << sink << "\n";
    return 0;
}
