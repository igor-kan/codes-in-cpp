#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_bridges_tarjan_lowlink {

std::vector<std::pair<int, int>> find_undirected_bridges(int n, const std::vector<std::pair<int, int>>& edges) {
    if (n <= 0) throw std::invalid_argument("n must be positive");
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
        auto [u, v] = edges[i];
        if (u < 0 || u >= n || v < 0 || v >= n) throw std::out_of_range("vertex out of range");
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    std::vector<int> tin(n, -1), low(n, -1);
    std::vector<std::pair<int, int>> bridges;
    int timer = 0;
    auto dfs = [&](auto& self, int u, int peid) -> void {
        tin[u] = low[u] = timer++;
        for (auto [v, eid] : adj[u]) {
            if (eid == peid) continue;
            if (tin[v] != -1) {
                low[u] = std::min(low[u], tin[v]);
            } else {
                self(self, v, eid);
                low[u] = std::min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    bridges.push_back({std::min(u, v), std::max(u, v)});
                }
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (tin[i] == -1) dfs(dfs, i, -1);
    }
    std::sort(bridges.begin(), bridges.end());
    return bridges;
}

} // namespace codes_bridges_tarjan_lowlink
