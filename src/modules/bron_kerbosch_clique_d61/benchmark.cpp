#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_bron_kerbosch_clique_d61;
    BronKerbosch bk(10);
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (((i * 13 + j * 7) % 5) != 0) bk.add_edge(i, j);
        }
    }
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        auto cliques = bk.maximal_cliques();
    sink = sink + static_cast<std::int64_t>(cliques.size());
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "bron_kerbosch_clique_d61 us=" << us << " sink=" << sink << "\n";
    return 0;
}
