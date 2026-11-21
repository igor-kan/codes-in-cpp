#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_li_chao_convex_line_tree;
    LiChaoTree b_lc(32);
    b_lc.add_line(2, 10);
    b_lc.add_line(-3, 90);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += b_lc.query(16);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "li_chao_convex_line_tree us=" << us << " sink=" << sink << "\n";
    return 0;
}
