#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_euler_tour_forest_dyn;
    EulerSubtreeIndex et(4, 0, {{0,1},{1,2},{2,3}}, {1,2,3,4});
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += et.query_subtree_sum(1);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "euler_tour_forest_dyn us=" << us << " sink=" << sink << "\n";
    return 0;
}
