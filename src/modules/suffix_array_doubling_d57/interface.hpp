#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_suffix_array_doubling_d57 {
std::vector<int> build_suffix_array(const std::string& s);
bool sa_contains(const std::string& text, const std::vector<int>& sa, const std::string& pat);

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_suffix_array_doubling_d57
