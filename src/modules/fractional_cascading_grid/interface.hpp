#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_fractional_cascading_grid {
class FractionalCascader {
public:
    explicit FractionalCascader(const std::vector<std::vector<std::int64_t>>& catalogs);
    std::vector<std::int64_t> query_lower_bounds(std::int64_t x) const;
private:
    std::vector<std::vector<std::int64_t>> raw_;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_fractional_cascading_grid
