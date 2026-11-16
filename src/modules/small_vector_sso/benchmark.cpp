#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    std::size_t sink = 0;
    codes_small_vector_sso::SmallVecInt v; int64_t tmp[12]; for(int i=0;i<12;++i) tmp[i]=i;
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        v.clear(); codes_small_vector_sso::append_range_fast(v, tmp, 12); sink += v.len;
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "small_vector_sso ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
