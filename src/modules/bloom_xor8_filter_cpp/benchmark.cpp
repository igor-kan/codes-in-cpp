#include "interface.hpp"
#include <chrono>
#include <iostream>


int main() {
    using namespace codes_bloom_xor8_filter_cpp;
    std::vector<std::uint64_t> ks(256); for(int i=0;i<256;++i) ks[i]=i*17+1; auto f=build_xor8_filter(ks);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += xor8_contains(f, static_cast<std::uint64_t>((iter % 300) * 17 + 1)) ? 1 : 0;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "bloom_xor8_filter_cpp us=" << us << " sink=" << sink << "\n";
    return 0;
}
