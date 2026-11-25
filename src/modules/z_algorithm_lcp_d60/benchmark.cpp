#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_z_algorithm_lcp_d60;
    std::string txt = "abcababcababcabc";
    std::string pat = "abcab";
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        auto hits = z_find_all(txt, pat);
    sink = sink + static_cast<std::int64_t>(hits.size());
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "z_algorithm_lcp_d60 us=" << us << " sink=" << sink << "\n";
    return 0;
}
