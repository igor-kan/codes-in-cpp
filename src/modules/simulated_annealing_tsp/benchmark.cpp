#include "interface.hpp"
#include <chrono>
#include <iostream>


int main() {
    using namespace codes_simulated_annealing_tsp;
    std::vector<Point2D> pts; for(int i=0;i<16;++i) pts.push_back({static_cast<double>(i%4), static_cast<double>(i/4)});
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        auto r = anneal_tsp_2opt(pts, 40, static_cast<std::uint64_t>(iter + 1)); sink += static_cast<std::int64_t>(r.total_length);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "simulated_annealing_tsp us=" << us << " sink=" << sink << "\n";
    return 0;
}
