#include "interface.hpp"

namespace codes_heavy_light_euler_tour {

EulerSubtreeEngine::EulerSubtreeEngine(int n, const std::vector<std::pair<int, int>>& edges, const std::vector<std::int64_t>& init)
    : n_(n), bit_(static_cast<std::size_t>(n + 1), 0) {
    validate_rooted_tree(n, edges, init);
    std::vector<std::vector<int>> adj(static_cast<std::size_t>(n));
    for (const auto& e : edges) {
        adj[static_cast<std::size_t>(e.first)].push_back(e.second);
        adj[static_cast<std::size_t>(e.second)].push_back(e.first);
    }
    idx_.tin.assign(static_cast<std::size_t>(n), 0);
    idx_.tout.assign(static_cast<std::size_t>(n), 0);
    int timer = 0;
    auto dfs = [&](auto& self, int u, int p) -> void {
        idx_.tin[static_cast<std::size_t>(u)] = timer++;
        idx_.order.push_back(u);
        for (int v : adj[static_cast<std::size_t>(u)]) {
            if (v != p) self(self, v, u);
        }
        idx_.tout[static_cast<std::size_t>(u)] = timer - 1;
    };
    dfs(dfs, 0, -1);
    for (int i = 0; i < n; ++i) {
        bit_add(idx_.tin[static_cast<std::size_t>(i)] + 1, init[static_cast<std::size_t>(i)]);
    }
}

void EulerSubtreeEngine::bit_add(int pos, std::int64_t v) {
    for (; pos <= n_; pos += pos & -pos) bit_[static_cast<std::size_t>(pos)] += v;
}

std::int64_t EulerSubtreeEngine::bit_prefix(int pos) const {
    std::int64_t s = 0;
    for (; pos > 0; pos -= pos & -pos) s += bit_[static_cast<std::size_t>(pos)];
    return s;
}

void EulerSubtreeEngine::add_point(int u, std::int64_t delta) {
    if (u < 0 || u >= n_) throw std::out_of_range("vertex out of range");
    bit_add(idx_.tin[static_cast<std::size_t>(u)] + 1, delta);
}

std::int64_t EulerSubtreeEngine::subtree_sum(int u) const {
    if (u < 0 || u >= n_) throw std::out_of_range("vertex out of range");
    int l = idx_.tin[static_cast<std::size_t>(u)];
    int r = idx_.tout[static_cast<std::size_t>(u)];
    return bit_prefix(r + 1) - bit_prefix(l);
}

} // namespace codes_heavy_light_euler_tour
