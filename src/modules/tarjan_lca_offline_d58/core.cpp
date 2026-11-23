#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_tarjan_lca_offline_d58 {

std::vector<int> tarjan_offline_lca(int n, int root, const std::vector<std::pair<int, int>>& edges, const std::vector<std::pair<int, int>>& queries) {
    std::vector<std::vector<int>> adj(n);
    for (auto [u, v] : edges) { adj[u].push_back(v); adj[v].push_back(u); }
    std::vector<std::vector<std::pair<int, int>>> qs(n);
    for (int i = 0; i < static_cast<int>(queries.size()); ++i) {
        auto [u, v] = queries[i];
        qs[u].push_back({v, i});
        qs[v].push_back({u, i});
    }
    std::vector<int> p(n), anc(n), ans(queries.size(), -1);
    std::vector<bool> vis(n, false);
    for (int i = 0; i < n; ++i) p[i] = anc[i] = i;
    auto find = [&](int x) -> int {
        while (p[x] != x) { p[x] = p[p[x]]; x = p[x]; }
        return x;
    };
    auto unite = [&](int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) p[rb] = ra;
    };
    auto dfs = [&](auto& self, int u, int par) -> void {
        anc[u] = u;
        for (int v : adj[u]) {
            if (v == par) continue;
            self(self, v, u);
            unite(u, v);
            anc[find(u)] = u;
        }
        vis[u] = true;
        for (auto [v, idx] : qs[u]) {
            if (vis[v]) ans[idx] = anc[find(v)];
        }
    };
    dfs(dfs, root, -1);
    return ans;
}

} // namespace codes_tarjan_lca_offline_d58
