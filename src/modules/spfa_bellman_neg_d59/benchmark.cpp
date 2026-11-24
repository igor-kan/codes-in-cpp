#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_spfa_bellman_neg_d59;
    std::vector<std::vector<SpfaEdge>> bg(3); bg[0] = {{1, 2}}; bg[1] = {{2, -1}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += spfa_distances(3, 0, bg).second[2];
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "spfa_bellman_neg_d59 us=" << us << " sink=" << sink << "\n";
    return 0;
}
