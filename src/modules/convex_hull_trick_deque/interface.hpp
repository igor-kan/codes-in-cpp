#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_convex_hull_trick_deque {
class MonotoneCht {
public:
    void add_line(std::int64_t m, std::int64_t b);
    std::int64_t query(std::int64_t x);
private:
    std::vector<ChtLine> hull_;
    std::size_t head_ = 0;
    static bool bad(ChtLine l1, ChtLine l2, ChtLine l3);
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_convex_hull_trick_deque
