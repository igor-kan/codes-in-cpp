#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_bron_kerbosch_clique_d61 {
class BronKerbosch {
public:
    explicit BronKerbosch(int vertices);
    void add_edge(int u, int v);
    bool adjacent(int u, int v) const;
    std::vector<std::vector<int>> maximal_cliques() const;
    CliqueSummary summary() const;
    int vertex_count() const;
private:
    int n_ = 0;
    std::vector<std::vector<char>> adj_;
    void expand(std::vector<int> r, std::vector<int> p, std::vector<int> x,
                std::vector<std::vector<int>>& out) const;
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_bron_kerbosch_clique_d61
