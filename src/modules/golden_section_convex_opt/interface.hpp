#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_golden_section_convex_opt {
using RealFn1D = double(*)(double);
Minima1D golden_section_minimize(RealFn1D f, double a, double b, double tol);

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_golden_section_convex_opt
