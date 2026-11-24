#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_monotone_cht_env_d59;
    MonotoneCht bch; bch.add_decreasing(3, 5); bch.add_decreasing(-2, 40);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += bch.query_increasing(8);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "monotone_cht_env_d59 us=" << us << " sink=" << sink << "\n";
    return 0;
}
