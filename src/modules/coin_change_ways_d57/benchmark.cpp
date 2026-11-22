#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_coin_change_ways_d57;
    std::vector<int> b_c = {1, 2, 5, 10};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += count_coin_combinations(b_c, 20);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "coin_change_ways_d57 us=" << us << " sink=" << sink << "\n";
    return 0;
}
