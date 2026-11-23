#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_treap_implicit_rev_d58 {
void reverse_subarray_twice_check(std::vector<long long>& xs, int l, int r);
long long subarray_sum(const std::vector<long long>& xs, int l, int r);

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_treap_implicit_rev_d58
