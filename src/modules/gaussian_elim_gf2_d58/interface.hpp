#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_gaussian_elim_gf2_d58 {
uint64_t gf2_max_subset_xor(const std::vector<uint64_t>& nums);
int gf2_basis_rank(const std::vector<uint64_t>& nums);

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_gaussian_elim_gf2_d58
