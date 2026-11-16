#include "interface.hpp"
#include <algorithm>

namespace codes_lru_k_eviction_cache {
Status verify_lruk_invariants(const LruKCache& cache) {
    if (cache.slots.size() > cache.stats.capacity) return Status::InvariantViolation;
    std::vector<int64_t> ks;
    ks.reserve(cache.slots.size());
    for (const auto& kv : cache.slots) ks.push_back(kv.first);
    std::sort(ks.begin(), ks.end());
    if (std::adjacent_find(ks.begin(), ks.end()) != ks.end()) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_lru_k_eviction_cache
