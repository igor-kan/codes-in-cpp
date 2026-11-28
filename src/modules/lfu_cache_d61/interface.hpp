#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_lfu_cache_d61 {
class LfuCache {
public:
    explicit LfuCache(std::size_t capacity);
    bool get(std::int64_t key, std::int64_t& out);
    void put(std::int64_t key, std::int64_t value);
    std::size_t size() const;
private:
    std::size_t cap_;
    std::vector<std::int64_t> keys_;
    std::vector<std::int64_t> vals_;
    std::vector<std::int64_t> freq_;
    std::vector<std::int64_t> stamp_;
    std::int64_t tick_ = 0;
    int find(std::int64_t key) const;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_lfu_cache_d61
