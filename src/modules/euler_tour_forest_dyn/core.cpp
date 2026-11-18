#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_euler_tour_forest_dyn {

void EulerSubtreeIndex::bit_add(int idx, std::int64_t delta) {
    for (int i = idx + 1; i <= n_; i += i & -i) bit_[i] += delta;
}

std::int64_t EulerSubtreeIndex::bit_sum(int idx) const {
    std::int64_t s = 0;
    for (int i = idx + 1; i > 0; i -= i & -i) s += bit_[i];
    return s;
}

EulerSubtreeIndex::EulerSubtreeIndex(int n, int root, const std::vector<std::pair<int, int>>& edges, const std::vector<std::int64_t>& init_w)
    : n_(n), range_(n), bit_(n + 1, 0) {
    std::vector<std::vector<int>> adj(n);
    for (auto [u, v] : edges) { adj[u].push_back(v); adj[v].push_back(u); }
    int timer = 0;
    auto dfs = [&](auto& self, int u, int p) -> void {
        range_[u].tin = timer++;
        for (int w : adj[u]) if (w != p) self(self, w, u);
        range_[u].tout = timer - 1;
    };
    dfs(dfs, root, -1);
    for (int u = 0; u < n; ++u) bit_add(range_[u].tin, init_w[u]);
}

void EulerSubtreeIndex::add_vertex_weight(int u, std::int64_t delta) {
    bit_add(range_[u].tin, delta);
}

std::int64_t EulerSubtreeIndex::query_subtree_sum(int u) const {
    return bit_sum(range_[u].tout) - (range_[u].tin > 0 ? bit_sum(range_[u].tin - 1) : 0);
}

} // namespace codes_euler_tour_forest_dyn
