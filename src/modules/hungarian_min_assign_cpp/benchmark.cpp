#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_hungarian_min_assign_cpp;
    std::vector<std::vector<std::int64_t>> c = {{4,1,3},{2,0,5},{3,2,2}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += hungarian_min_cost(c).total_cost;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "hungarian_min_assign_cpp us=" << us << " sink=" << sink << "\n";
    return 0;
}
