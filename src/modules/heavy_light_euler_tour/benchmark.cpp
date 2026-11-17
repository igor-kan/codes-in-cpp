#include "interface.hpp"
#include <chrono>
#include <iostream>


int main() {
    using namespace codes_heavy_light_euler_tour;
    std::vector<std::pair<int,int>> e; std::vector<std::int64_t> w(64,1); for(int i=1;i<64;++i) e.emplace_back((i-1)/2,i); EulerSubtreeEngine eng(64,e,w);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += eng.subtree_sum(iter % 64);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "heavy_light_euler_tour us=" << us << " sink=" << sink << "\n";
    return 0;
}
