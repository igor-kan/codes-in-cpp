#include "interface.hpp"
#include <chrono>
#include <iostream>


int main() {
    using namespace codes_wavelet_tree_range_kth;
    std::vector<int> a(128); for(int i=0;i<128;++i) a[i]=(i*17)%30; WaveletTree wt(a, 0, 29);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += wt.range_kth(iter % 40, 80 + (iter % 40), 10);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "wavelet_tree_range_kth us=" << us << " sink=" << sink << "\n";
    return 0;
}
