#include "interface.hpp"
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    std::size_t sink = 0;
    codes_splay_tree_amortized::SplayTree t; std::vector<long long> k(256); for(int i=0;i<256;++i) k[i]=i*2; codes_splay_tree_amortized::splay_insert_sorted_batch(t, k);
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        if (codes_splay_tree_amortized::splay_contains(t, (it * 13) % 512)) sink++;
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "splay_tree_amortized ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
