#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_lru_k_eviction_cache {
uint64_t count_hits_fast(std::size_t cap, const std::vector<int64_t>& trace);

std::vector<uint64_t> batch_simulate_lru2(std::size_t cap, const std::vector<std::vector<int64_t>>& traces) {
    std::vector<uint64_t> out(traces.size(), 0);
    if (traces.empty()) return out;
    std::size_t nt = std::min<std::size_t>(4, traces.size());
    std::vector<std::thread> pool;
    for (std::size_t t = 0; t < nt; ++t) {
        pool.emplace_back([&, t]() {
            for (std::size_t i = t; i < traces.size(); i += nt) {
                out[i] = count_hits_fast(cap, traces[i]);
            }
        });
    }
    for (auto& th : pool) th.join();
    return out;
}
} // namespace codes_lru_k_eviction_cache
