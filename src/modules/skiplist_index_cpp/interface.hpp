#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_skiplist_index_cpp {
class SkipListIndex {
public:
    SkipListIndex();
    bool upsert(std::int64_t key, std::int64_t val);
    bool find(std::int64_t key, std::int64_t& out) const;
    std::vector<std::int64_t> range_values(std::int64_t lo, std::int64_t hi) const;
    int size() const { return count_; }
    const std::vector<SkipNode>& raw_nodes() const { return nodes_; }

private:
    std::vector<SkipNode> nodes_;
    int max_level_ = 1;
    int count_ = 0;
    std::uint64_t rng_ = 0x9E3779B97F4A7C15ULL;
    int random_height();
};

void validate_range_bounds(std::int64_t lo, std::int64_t hi);
std::size_t fast_count_present(const SkipListIndex& sl, const std::vector<std::int64_t>& probes);
std::vector<std::size_t> parallel_lookup_counts(const std::vector<std::int64_t>& keys,
                                              const std::vector<std::vector<std::int64_t>>& probe_batches);
void verify_skiplist_sorted(const SkipListIndex& sl);
} // namespace codes_skiplist_index_cpp
