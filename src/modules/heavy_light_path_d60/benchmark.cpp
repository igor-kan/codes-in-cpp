#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_heavy_light_path_d60;
    TreeLcaSolver tr(6, {{0,1,2},{0,2,5},{1,3,4},{1,4,1},{2,5,3}});
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink = sink + tr.path_dist(iter % 6, (iter + 3) % 6);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "heavy_light_path_d60 us=" << us << " sink=" << sink << "\n";
    return 0;
}
