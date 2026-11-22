#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_dinic_level_flow_d57 {
class DinicSolver {
public:
    explicit DinicSolver(int n);
    void add_edge(int u, int v, long long cap);
    long long max_flow(int s, int t);
private:
    int n_;
    std::vector<std::vector<DinicArc>> adj_;
    std::vector<int> level_;
    std::vector<int> ptr_;
    bool bfs(int s, int t);
    long long dfs(int u, int t, long long pushed);
};

void validate_problem_size(int n);
std::int64_t fast_checksum_span(const std::vector<std::int64_t>& xs);
std::vector<std::int64_t> parallel_checksum_batches(const std::vector<std::vector<std::int64_t>>& batches);
void verify_module_postcondition(bool ok, const char* msg);
} // namespace codes_dinic_level_flow_d57
