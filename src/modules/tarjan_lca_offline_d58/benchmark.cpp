#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_tarjan_lca_offline_d58;
    std::vector<std::pair<int, int>> b_e = {{0,1},{1,2},{2,3}};
    std::vector<std::pair<int, int>> b_q = {{2,3},{0,3}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += tarjan_offline_lca(4, 0, b_e, b_q)[0];
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "tarjan_lca_offline_d58 us=" << us << " sink=" << sink << "\n";
    return 0;
}
