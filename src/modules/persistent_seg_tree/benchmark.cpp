#include "interface.hpp"
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    std::size_t sink = 0;
    auto pst = codes_persistent_seg_tree::pst_create(std::vector<long long>(256, 1)); for(std::size_t i=0;i<64;++i) codes_persistent_seg_tree::pst_update(pst, i, (i*13)%256, 2);
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        sink += static_cast<std::size_t>(codes_persistent_seg_tree::pst_query_sum(pst, static_cast<std::size_t>(it % 65), 10, 200));
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "persistent_seg_tree ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
