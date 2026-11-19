#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_persistent_segtree_kth {
class PersistentFreqTree {
public:
    explicit PersistentFreqTree(int dom);
    int add(int prev_root, int l, int r, int pos);
    int kth(int root_l, int root_r, int l, int r, int k) const;
private:
    int dom_;
    std::vector<PSegNode> nodes_;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_persistent_segtree_kth
