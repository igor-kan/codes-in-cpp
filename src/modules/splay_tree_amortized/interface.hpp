#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_splay_tree_amortized {
void splay_pull(SplayTree& tree, int x);
void splay_rotate(SplayTree& tree, int x);
void splay(SplayTree& tree, int x);
bool splay_insert(SplayTree& tree, long long key);
bool splay_contains(SplayTree& tree, long long key);
bool splay_erase(SplayTree& tree, long long key);
bool kth_element(SplayTree& tree, std::size_t k, long long& out_key);
Status validate_tree_limits(const SplayTree& tree, std::size_t cap);
void splay_insert_sorted_batch(SplayTree& tree, const std::vector<long long>& sorted_keys);
std::vector<std::size_t> batch_count_hits(const std::vector<long long>& dict, const std::vector<std::vector<long long>>& queries);
Status verify_splay_bst(const SplayTree& tree, int x, long long lo, long long hi);
} // namespace codes_splay_tree_amortized
