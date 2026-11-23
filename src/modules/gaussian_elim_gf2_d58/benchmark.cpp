#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_gaussian_elim_gf2_d58;
    std::vector<uint64_t> b_xs = {5, 11, 23, 47};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += static_cast<long long>(gf2_max_subset_xor(b_xs));
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "gaussian_elim_gf2_d58 us=" << us << " sink=" << sink << "\n";
    return 0;
}
