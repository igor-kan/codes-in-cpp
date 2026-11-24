#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_monotone_cht_env_d59 {
class MonotoneCht {
public:
    void add_decreasing(long long m, long long b);
    long long query_increasing(long long x);
private:
    std::vector<ChtLine> dq_;
    std::size_t head_ = 0;
    static bool bad(const ChtLine& a, const ChtLine& b, const ChtLine& c);
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_monotone_cht_env_d59
