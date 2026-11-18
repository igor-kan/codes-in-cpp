#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_li_chao_segment_lines;
    LiChaoTree lc(64); lc.add_line(2, 5); lc.add_line(-1, 40);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += lc.query(iter & 31);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "li_chao_segment_lines us=" << us << " sink=" << sink << "\n";
    return 0;
}
