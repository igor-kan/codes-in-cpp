#include "interface.hpp"

namespace codes_lru_k_eviction_cache {
uint64_t count_hits_fast(std::size_t cap, const std::vector<int64_t>& trace) {
    if (validate_capacity(cap) != Status::Ok) return 0;
    LruKCache c = make_lruk(cap);
    uint64_t hits = 0;
    for (int64_t k : trace) {
        int64_t tmp = 0;
        if (get_page(c, k, tmp)) ++hits;
        else put_page(c, k, k);
    }
    return hits;
}
} // namespace codes_lru_k_eviction_cache
