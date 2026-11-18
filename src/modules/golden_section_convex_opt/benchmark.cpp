#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_golden_section_convex_opt;
    auto fn = +[](double x) { return (x - 2.0) * (x - 2.0); };
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += static_cast<std::int64_t>(golden_section_minimize(fn, 0.0, 5.0, 1e-5).iterations);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "golden_section_convex_opt us=" << us << " sink=" << sink << "\n";
    return 0;
}
