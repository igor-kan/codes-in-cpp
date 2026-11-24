#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_meet_in_middle_sum_d59;
    std::vector<long long> bxs = {2, 5, 8, 13, 21, 34};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += subset_sum_mim(bxs, 42) ? 1 : 0;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "meet_in_middle_sum_d59 us=" << us << " sink=" << sink << "\n";
    return 0;
}
