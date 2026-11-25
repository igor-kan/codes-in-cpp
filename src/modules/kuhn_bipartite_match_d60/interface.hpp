#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_kuhn_bipartite_match_d60 {
int kuhn_max_matching(int nl, int nr, const std::vector<BipartiteEdge>& edges);

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_kuhn_bipartite_match_d60
