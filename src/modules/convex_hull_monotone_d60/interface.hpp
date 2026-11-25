#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_convex_hull_monotone_d60 {
std::vector<Pt2D> convex_hull_ccw(std::vector<Pt2D> pts);
std::int64_t polygon_area2x(const std::vector<Pt2D>& poly);

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_convex_hull_monotone_d60
