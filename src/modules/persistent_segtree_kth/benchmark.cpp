#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_persistent_segtree_kth;
    PersistentFreqTree pst(8); int r1 = pst.add(0, 0, 7, 3); int r2 = pst.add(r1, 0, 7, 6);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        sink += pst.kth(0, r2, 0, 7, 2);
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "persistent_segtree_kth us=" << us << " sink=" << sink << "\n";
    return 0;
}
