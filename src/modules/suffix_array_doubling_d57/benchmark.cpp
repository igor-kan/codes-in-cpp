#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_suffix_array_doubling_d57;
    std::string b_s = "abracadabra";
    auto b_sa = build_suffix_array(b_s);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += sa_contains(b_s, b_sa, "cad") ? 1 : 0;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "suffix_array_doubling_d57 us=" << us << " sink=" << sink << "\n";
    return 0;
}
