#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_li_chao_segment_lines {
class LiChaoTree {
public:
    explicit LiChaoTree(int max_x);
    void add_line(std::int64_t m, std::int64_t b);
    std::int64_t query(int x) const;
private:
    int n_;
    std::vector<AffineLine> tree_;
    void insert_rec(int v, int l, int r, AffineLine nw);
    std::int64_t query_rec(int v, int l, int r, int x) const;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_li_chao_segment_lines
