#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_scapegoat_weight_bst {
class ScapegoatTree {
public:
    void insert(std::int64_t key);
    bool contains(std::int64_t key) const;
    std::int64_t kth(int k) const;
    int size() const { return root_ < 0 ? 0 : pool_[root_].sz; }
private:
    int root_ = -1;
    std::vector<SgNode> pool_;
    int sz(int u) const { return u < 0 ? 0 : pool_[u].sz; }
    void flatten(int u, std::vector<int>& out);
    int build_flat(const std::vector<int>& flat, int lo, int hi);
    int rebuild(int u);
    int insert_rec(int u, std::int64_t key);
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_scapegoat_weight_bst
