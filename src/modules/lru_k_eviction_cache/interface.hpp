#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_lru_k_eviction_cache {
LruKCache make_lruk(std::size_t capacity);
Status validate_capacity(std::size_t capacity);
bool get_page(LruKCache& cache, int64_t key, int64_t& val_out);
void put_page(LruKCache& cache, int64_t key, int64_t val);
std::size_t cache_size(const LruKCache& cache);
uint64_t eviction_count(const LruKCache& cache);
std::vector<uint64_t> batch_simulate_lru2(std::size_t cap, const std::vector<std::vector<int64_t>>& traces);
Status verify_lruk_invariants(const LruKCache& cache);
} // namespace codes_lru_k_eviction_cache
