#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_sliding_window_median_heaps {
std::vector<double> sliding_window_medians(const std::vector<std::int64_t>& nums, std::size_t k);
void validate_window(std::size_t n, std::size_t k);
double fast_median_sort_slice(std::vector<std::int64_t> slice);
std::vector<std::vector<double>> parallel_median_streams(const std::vector<std::vector<std::int64_t>>& streams, std::size_t k);
void verify_medians_oracle(const std::vector<std::int64_t>& nums, std::size_t k, const std::vector<double>& got);
} // namespace codes_sliding_window_median_heaps
