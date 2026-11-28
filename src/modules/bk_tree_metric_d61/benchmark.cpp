#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_bk_tree_metric_d61;
    BkTree bk;
    bk.insert("alpha");
    bk.insert("alpine");
    bk.insert("beta");
    bk.insert("better");
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        auto hits = bk.search("alpah", 2);
    sink = sink + static_cast<std::int64_t>(hits.size());
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "bk_tree_metric_d61 us=" << us << " sink=" << sink << "\n";
    return 0;
}
