#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_bloom_xor8_filter_cpp {
Xor8Filter build_xor8_filter(const std::vector<std::uint64_t>& keys);
bool xor8_contains(const Xor8Filter& f, std::uint64_t key);
void validate_unique_keys(const std::vector<std::uint64_t>& keys);
std::size_t xor8_fast_count_hits(const Xor8Filter& f, const std::vector<std::uint64_t>& probes);
std::vector<std::size_t> parallel_xor8_probe(const Xor8Filter& f, const std::vector<std::vector<std::uint64_t>>& batches);
void verify_xor8_no_false_negatives(const Xor8Filter& f, const std::vector<std::uint64_t>& keys);
} // namespace codes_bloom_xor8_filter_cpp
