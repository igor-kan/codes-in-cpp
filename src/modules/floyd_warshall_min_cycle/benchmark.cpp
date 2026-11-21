#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_floyd_warshall_min_cycle;
    std::vector<std::vector<long long>> b_m = {{0, 5, 12}, {2, 0, 4}, {9, 3, 0}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += floyd_warshall_solve(b_m).dist[0][2];
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "floyd_warshall_min_cycle us=" << us << " sink=" << sink << "\n";
    return 0;
}
