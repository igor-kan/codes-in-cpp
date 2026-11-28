#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_chtholly_tree_d61 {
class ChthollyTree {
public:
    explicit ChthollyTree(int size);
    void assign(int l, int r, std::int64_t val);
    std::int64_t range_sum(int l, int r) const;
    std::size_t interval_count() const;
private:
    std::vector<IntervalNode> segs_;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_chtholly_tree_d61
