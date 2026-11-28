#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_leftist_heap_d61 {
class LeftistHeap {
public:
    int make(std::int64_t key);
    int meld(int a, int b);
    std::int64_t peek_min(int root) const;
    int pop_min(int root);
    std::int64_t total(int root) const;
private:
    std::vector<LeftistNode> nodes_;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_leftist_heap_d61
