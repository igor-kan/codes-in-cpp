#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_scc_condensation_d59;
    std::vector<std::pair<int, int>> bes = {{0,1},{1,2},{2,0},{2,3}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += tarjan_scc_condense(4, bes).comp_count;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "scc_condensation_d59 us=" << us << " sink=" << sink << "\n";
    return 0;
}
