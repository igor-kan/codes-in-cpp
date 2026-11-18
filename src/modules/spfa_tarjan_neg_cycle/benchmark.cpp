#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_spfa_tarjan_neg_cycle;
    std::vector<WEdge> es = {{0,1,1},{1,2,-3},{2,0,1}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += static_cast<std::int64_t>(find_negative_cycle(3, es).size());
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "spfa_tarjan_neg_cycle us=" << us << " sink=" << sink << "\n";
    return 0;
}
