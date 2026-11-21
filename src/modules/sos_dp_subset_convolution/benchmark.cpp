#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_sos_dp_subset_convolution;
    std::vector<long long> b_f(64, 1);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += sos_zeta(b_f, 6).back();
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "sos_dp_subset_convolution us=" << us << " sink=" << sink << "\n";
    return 0;
}
