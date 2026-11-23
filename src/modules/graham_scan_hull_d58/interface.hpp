#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_graham_scan_hull_d58 {
long long convex_hull_area2(std::vector<std::pair<long long, long long>> pts);

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_graham_scan_hull_d58
