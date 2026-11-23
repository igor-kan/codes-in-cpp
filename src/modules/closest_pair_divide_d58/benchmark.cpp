#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_closest_pair_divide_d58;
    std::vector<std::pair<long long, long long>> b_p = {{0,0},{3,4},{1,2},{9,9}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += closest_pair_dist2(b_p);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "closest_pair_divide_d58 us=" << us << " sink=" << sink << "\n";
    return 0;
}
