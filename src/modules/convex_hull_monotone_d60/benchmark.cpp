#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_convex_hull_monotone_d60;
    std::vector<Pt2D> pts = {{0,0},{10,0},{10,10},{0,10},{3,4},{7,2},{5,8}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        auto h = convex_hull_ccw(pts);
    sink = sink + polygon_area2x(h);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "convex_hull_monotone_d60 us=" << us << " sink=" << sink << "\n";
    return 0;
}
