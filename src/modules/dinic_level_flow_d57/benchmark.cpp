#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_dinic_level_flow_d57;
    DinicSolver b_dn(4);
    b_dn.add_edge(0, 1, 10); b_dn.add_edge(1, 3, 8);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += b_dn.max_flow(0, 3);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "dinic_level_flow_d57 us=" << us << " sink=" << sink << "\n";
    return 0;
}
