#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_kruskal_dsu_mst_weight;
    std::vector<WeightedLink> b_es = {{0, 1, 3}, {1, 2, 5}, {2, 3, 2}, {0, 3, 9}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += kruskal_mst(4, b_es).first;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "kruskal_dsu_mst_weight us=" << us << " sink=" << sink << "\n";
    return 0;
}
