#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_segment_lazy_add_d60;
    LazySegTree seg(64);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        int l = iter & 31, r = l + 15;
    seg.range_add(l, r, 1);
    sink = sink + seg.range_sum(l, r);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "segment_lazy_add_d60 us=" << us << " sink=" << sink << "\n";
    return 0;
}
