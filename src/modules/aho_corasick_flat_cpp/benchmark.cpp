#include "interface.hpp"
#include <chrono>
#include <iostream>


int main() {
    using namespace codes_aho_corasick_flat_cpp;
    FlatAhoCorasick ac({"alpha", "beta", "gamma"}); std::string doc = "alphabeta_gamma_alpha";
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += ac.count_matches(doc);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "aho_corasick_flat_cpp us=" << us << " sink=" << sink << "\n";
    return 0;
}
