#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    std::size_t sink = 0;
    auto c = codes_lru_k_eviction_cache::make_lruk(64);
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        for(int64_t k=0;k<128;++k){ int64_t v=0; if(!codes_lru_k_eviction_cache::get_page(c,k%96,v)) codes_lru_k_eviction_cache::put_page(c,k%96,k); else sink+=static_cast<std::size_t>(v); }
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "lru_k_eviction_cache ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
