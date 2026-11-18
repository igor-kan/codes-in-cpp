#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_scapegoat_weight_bst;
    ScapegoatTree sg; for (int i = 1; i <= 16; ++i) sg.insert(i);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += sg.kth(iter & 15);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "scapegoat_weight_bst us=" << us << " sink=" << sink << "\n";
    return 0;
}
