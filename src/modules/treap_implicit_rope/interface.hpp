#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_treap_implicit_rope {
std::uint64_t next_prio(ImplicitTreapArena& arena);
int new_node(ImplicitTreapArena& arena, long long val);
void push_down(ImplicitTreapArena& arena, int t);
void pull_up(ImplicitTreapArena& arena, int t);
void split_by_index(ImplicitTreapArena& arena, int t, std::size_t k, int& left_out, int& right_out);
int merge_treaps(ImplicitTreapArena& arena, int l, int r);
void insert_at(ImplicitTreapArena& arena, std::size_t idx, long long val);
void reverse_range(ImplicitTreapArena& arena, std::size_t l, std::size_t r);
long long query_sum(ImplicitTreapArena& arena, std::size_t l, std::size_t r);
void to_vector(ImplicitTreapArena& arena, int t, std::vector<long long>& out);
Status validate_range(const ImplicitTreapArena& arena, std::size_t l, std::size_t r);
void build_linear_fast(ImplicitTreapArena& arena, const std::vector<long long>& vals);
std::vector<long long> parallel_chunk_sums(const std::vector<std::vector<long long>>& seqs);
Status verify_treap_invariants(const ImplicitTreapArena& arena, int t);
} // namespace codes_treap_implicit_rope
