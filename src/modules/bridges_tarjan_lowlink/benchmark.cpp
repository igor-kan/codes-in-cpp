#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_bridges_tarjan_lowlink;
    std::vector<std::pair<int, int>> b_edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += static_cast<long long>(find_undirected_bridges(4, b_edges).size());
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "bridges_tarjan_lowlink us=" << us << " sink=" << sink << "\n";
    return 0;
}
