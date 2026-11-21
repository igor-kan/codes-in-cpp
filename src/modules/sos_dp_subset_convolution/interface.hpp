#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_sos_dp_subset_convolution {
std::vector<long long> sos_zeta(std::vector<long long> f, int bits);
std::vector<long long> sos_mobius(std::vector<long long> f, int bits);

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_sos_dp_subset_convolution
