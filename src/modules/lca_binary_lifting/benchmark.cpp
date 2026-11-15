#include "interface.hpp"
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    std::size_t sink = 0;
    std::vector<std::pair<std::size_t,std::size_t>> e; for(std::size_t i=1;i<500;++i) e.push_back({(i-1)/2,i}); auto idx = codes_lca_binary_lifting::build_lca(500, e, 0);
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        sink += codes_lca_binary_lifting::tree_distance(idx, static_cast<std::size_t>(it%500), static_cast<std::size_t>((it*17+3)%500));
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "lca_binary_lifting ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
