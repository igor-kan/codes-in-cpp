#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_persistent_seg_tree {
PersistentSegTree pst_create(const std::vector<long long>& init_vals);
std::size_t pst_update(PersistentSegTree& pst, std::size_t version, std::size_t pos, long long delta);
long long pst_query_sum(const PersistentSegTree& pst, std::size_t version, std::size_t ql, std::size_t qr);
std::size_t pst_kth_prefix(const PersistentSegTree& pst, std::size_t ver_l, std::size_t ver_r, long long k);
Status validate_version_query(const PersistentSegTree& pst, std::size_t ver, std::size_t l, std::size_t r);
std::vector<long long> pst_batch_sums_fast(const PersistentSegTree& pst, const std::vector<std::size_t>& vers, std::size_t ql, std::size_t qr);
std::vector<long long> parallel_version_totals(const PersistentSegTree& pst);
Status verify_pst_node_sums(const PersistentSegTree& pst, int node, std::size_t l, std::size_t r);
} // namespace codes_persistent_seg_tree
