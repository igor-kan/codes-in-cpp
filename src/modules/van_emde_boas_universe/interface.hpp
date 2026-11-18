#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_van_emde_boas_universe {
class FlatVebSet {
public:
    explicit FlatVebSet(int universe = 65536);
    void insert(int x);
    void erase(int x);
    bool contains(int x) const;
    int successor(int x) const;
    int predecessor(int x) const;
private:
    int u_;
    std::vector<std::uint64_t> words_;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_van_emde_boas_universe
