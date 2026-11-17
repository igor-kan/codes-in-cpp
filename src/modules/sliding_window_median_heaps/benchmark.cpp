#include "interface.hpp"
#include <chrono>
#include <iostream>


int main() {
    using namespace codes_sliding_window_median_heaps;
    std::vector<std::int64_t> v(128); for(int i=0;i<128;++i) v[i]=(i*29)%50;
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        auto r = sliding_window_medians(v, 15); sink += static_cast<std::int64_t>(r[iter % r.size()]);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "sliding_window_median_heaps us=" << us << " sink=" << sink << "\n";
    return 0;
}
