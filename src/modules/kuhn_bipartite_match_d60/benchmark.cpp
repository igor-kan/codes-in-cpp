#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_kuhn_bipartite_match_d60;
    std::vector<BipartiteEdge> es = {{0,0},{0,1},{1,1},{1,2},{2,2},{3,0},{3,3}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink = sink + kuhn_max_matching(4, 4, es);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "kuhn_bipartite_match_d60 us=" << us << " sink=" << sink << "\n";
    return 0;
}
