#include "interface.hpp"
#include <algorithm>
#include <limits>

namespace codes_lru_k_eviction_cache {
LruKCache make_lruk(std::size_t capacity) {
    LruKCache c;
    c.stats.capacity = capacity == 0 ? 1 : capacity;
    c.slots.reserve(c.stats.capacity);
    return c;
}

static bool rank_worse(const LruKCache& cache, std::size_t a_idx, std::size_t b_idx) {
    const auto& ea = cache.slots[a_idx].second;
    const auto& eb = cache.slots[b_idx].second;
    uint8_t ta = (ea.hits < 2) ? 0 : 1;
    uint8_t tb = (eb.hits < 2) ? 0 : 1;
    if (ta != tb) return ta < tb;
    uint64_t sa = (ta == 0) ? ea.last_epoch : ea.prev_epoch;
    uint64_t sb = (tb == 0) ? eb.last_epoch : eb.prev_epoch;
    if (sa != sb) return sa < sb;
    return cache.slots[a_idx].first < cache.slots[b_idx].first;
}

bool get_page(LruKCache& cache, int64_t key, int64_t& val_out) {
    for (auto& kv : cache.slots) {
        if (kv.first == key) {
            ++cache.stats.cache_hits;
            ++cache.stats.epoch;
            kv.second.prev_epoch = kv.second.last_epoch;
            kv.second.last_epoch = cache.stats.epoch;
            if (kv.second.hits < 2) ++kv.second.hits;
            val_out = kv.second.value;
            return true;
        }
    }
    ++cache.stats.cache_misses;
    return false;
}

void put_page(LruKCache& cache, int64_t key, int64_t val) {
    ++cache.stats.epoch;
    for (auto& kv : cache.slots) {
        if (kv.first == key) {
            kv.second.value = val;
            kv.second.prev_epoch = kv.second.last_epoch;
            kv.second.last_epoch = cache.stats.epoch;
            if (kv.second.hits < 2) ++kv.second.hits;
            return;
        }
    }
    if (cache.slots.size() >= cache.stats.capacity) {
        std::size_t victim = 0;
        for (std::size_t i = 1; i < cache.slots.size(); ++i) {
            if (rank_worse(cache, i, victim)) victim = i;
        }
        cache.slots[victim] = cache.slots.back();
        cache.slots.pop_back();
        ++cache.stats.evictions;
    }
    cache.slots.push_back({key, Lru2Entry{val, 0, cache.stats.epoch, 1}});
}

std::size_t cache_size(const LruKCache& cache) { return cache.slots.size(); }
uint64_t eviction_count(const LruKCache& cache) { return cache.stats.evictions; }
} // namespace codes_lru_k_eviction_cache
