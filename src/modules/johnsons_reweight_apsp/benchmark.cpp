#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_johnsons_reweight_apsp;
    std::vector<WEdge> es = {{0,1,4},{1,2,-3},{2,3,2}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += johnson_apsp(4, es)[0][3];
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "johnsons_reweight_apsp us=" << us << " sink=" << sink << "\n";
    return 0;
}
