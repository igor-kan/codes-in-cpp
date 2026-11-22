#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_cartesian_min_tree_d57 {
std::pair<int, std::vector<CartNode>> build_cartesian_min_tree(const std::vector<long long>& xs);

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_cartesian_min_tree_d57
