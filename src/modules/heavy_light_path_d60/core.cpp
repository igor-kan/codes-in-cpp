#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_heavy_light_path_d60 {

TreeLcaSolver::TreeLcaSolver(int n, const std::vector<TreeEdge>& edges)
    : n_(n), logk_(1), dep_(n, 0), dist_(n, 0) {
    while ((1 << logk_) <= n_) ++logk_;
    up_.assign(logk_, std::vector<int>(n_, 0));
    std::vector<std::vector<std::pair<int, std::int64_t>>> adj(n_);
    for (const auto& e : edges) {
        adj[e.u].push_back({e.v, e.w});
        adj[e.v].push_back({e.u, e.w});
    }
    auto dfs = [&](auto& self, int u, int p) -> void {
        up_[0][u] = p;
        for (int k = 1; k < logk_; ++k) up_[k][u] = up_[k - 1][up_[k - 1][u]];
        for (auto [v, w] : adj[u]) {
            if (v == p) continue;
            dep_[v] = dep_[u] + 1;
            dist_[v] = dist_[u] + w;
            self(self, v, u);
        }
    };
    dfs(dfs, 0, 0);
}
int TreeLcaSolver::lca(int u, int v) const {
    if (dep_[u] < dep_[v]) std::swap(u, v);
    int diff = dep_[u] - dep_[v];
    for (int k = 0; k < logk_; ++k) {
        if ((diff >> k) & 1) u = up_[k][u];
    }
    if (u == v) return u;
    for (int k = logk_ - 1; k >= 0; --k) {
        if (up_[k][u] != up_[k][v]) {
            u = up_[k][u];
            v = up_[k][v];
        }
    }
    return up_[0][u];
}
std::int64_t TreeLcaSolver::path_dist(int u, int v) const {
    int w = lca(u, v);
    return dist_[u] + dist_[v] - 2 * dist_[w];
}

} // namespace codes_heavy_light_path_d60
