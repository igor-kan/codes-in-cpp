#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_stable_marriage_gale_d61;
    StableMarriage sm(8);
    for (int m = 0; m < 8; ++m) {
        std::vector<int> order;
        for (int j = 0; j < 8; ++j) order.push_back((j * 7 + m) % 8);
        sm.set_proposer_preferences(m, order);
    }
    for (int w = 0; w < 8; ++w) {
        std::vector<int> order;
        for (int j = 0; j < 8; ++j) order.push_back((j * 7 + 2 * w + 1) % 8);
        sm.set_receiver_preferences(w, order);
    }
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        auto match = sm.solve();
    sink = sink + match[iter % 8];
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "stable_marriage_gale_d61 us=" << us << " sink=" << sink << "\n";
    return 0;
}
