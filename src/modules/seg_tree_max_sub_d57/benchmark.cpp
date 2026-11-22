#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_seg_tree_max_sub_d57;
    MaxSubSegTree b_st({3, -1, 4, -2, 5});
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += b_st.query_best(0, 4);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "seg_tree_max_sub_d57 us=" << us << " sink=" << sink << "\n";
    return 0;
}
