#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_lru_k_eviction_cache {
struct Lru2Entry {
    int64_t value = 0;
    uint64_t prev_epoch = 0;
    uint64_t last_epoch = 0;
    uint8_t hits = 0;
};

struct LruKStats {
    std::size_t capacity = 0;
    uint64_t epoch = 0;
    uint64_t cache_hits = 0;
    uint64_t cache_misses = 0;
    uint64_t evictions = 0;
};

struct LruKCache {
    LruKStats stats;
    std::vector<std::pair<int64_t, Lru2Entry>> slots;
};
} // namespace codes_lru_k_eviction_cache
