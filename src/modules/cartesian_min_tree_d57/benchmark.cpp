#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_cartesian_min_tree_d57;
    std::vector<long long> b_xs = {9, 3, 7, 1, 8, 12, 10, 20};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += build_cartesian_min_tree(b_xs).first;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "cartesian_min_tree_d57 us=" << us << " sink=" << sink << "\n";
    return 0;
}
