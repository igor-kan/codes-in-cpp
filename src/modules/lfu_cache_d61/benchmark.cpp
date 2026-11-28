#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_lfu_cache_d61;
    LfuCache cache(8);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        cache.put(static_cast<std::int64_t>(iter % 16), static_cast<std::int64_t>(iter));
    std::int64_t value = 0;
    if (cache.get(static_cast<std::int64_t>(iter % 16), value)) sink = sink + value;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "lfu_cache_d61 us=" << us << " sink=" << sink << "\n";
    return 0;
}
