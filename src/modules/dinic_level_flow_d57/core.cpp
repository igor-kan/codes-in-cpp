#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_dinic_level_flow_d57 {

DinicSolver::DinicSolver(int n) : n_(n), adj_(n), level_(n), ptr_(n) {
    if (n <= 1) throw std::invalid_argument("n >= 2 required");
}

void DinicSolver::add_edge(int u, int v, long long cap) {
    if (u < 0 || u >= n_ || v < 0 || v >= n_ || cap < 0) throw std::invalid_argument("invalid arc");
    adj_[u].push_back({v, static_cast<int>(adj_[v].size()), cap});
    adj_[v].push_back({u, static_cast<int>(adj_[u].size()) - 1, 0});
}

bool DinicSolver::bfs(int s, int t) {
    std::fill(level_.begin(), level_.end(), -1);
    level_[s] = 0;
    std::vector<int> q = {s};
    for (std::size_t i = 0; i < q.size(); ++i) {
        int u = q[i];
        for (const auto& e : adj_[u]) {
            if (e.cap > 0 && level_[e.to] == -1) {
                level_[e.to] = level_[u] + 1;
                q.push_back(e.to);
            }
        }
    }
    return level_[t] != -1;
}

long long DinicSolver::dfs(int u, int t, long long pushed) {
    if (pushed == 0 || u == t) return pushed;
    for (int& cid = ptr_[u]; cid < static_cast<int>(adj_[u].size()); ++cid) {
        auto& e = adj_[u][cid];
        if (level_[u] + 1 != level_[e.to] || e.cap == 0) continue;
        long long tr = dfs(e.to, t, std::min(pushed, e.cap));
        if (tr == 0) continue;
        e.cap -= tr;
        adj_[e.to][e.rev].cap += tr;
        return tr;
    }
    return 0;
}

long long DinicSolver::max_flow(int s, int t) {
    long long flow = 0;
    const long long INF = std::numeric_limits<long long>::max() / 4;
    while (bfs(s, t)) {
        std::fill(ptr_.begin(), ptr_.end(), 0);
        while (long long pushed = dfs(s, t, INF)) flow += pushed;
    }
    return flow;
}

} // namespace codes_dinic_level_flow_d57
