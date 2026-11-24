#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_scc_condensation_d59 {

SccSummary tarjan_scc_condense(int n, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<int>> adj(n);
    for (auto [u, v] : edges) adj[u].push_back(v);
    std::vector<int> tin(n, -1), low(n, -1), comp(n, -1), stk;
    std::vector<bool> on_stk(n, false);
    int timer = 0, ccnt = 0;
    auto dfs = [&](auto& self, int u) -> void {
        tin[u] = low[u] = timer++;
        stk.push_back(u); on_stk[u] = true;
        for (int v : adj[u]) {
            if (tin[v] == -1) {
                self(self, v);
                low[u] = std::min(low[u], low[v]);
            } else if (on_stk[v]) {
                low[u] = std::min(low[u], tin[v]);
            }
        }
        if (low[u] == tin[u]) {
            while (true) {
                int x = stk.back(); stk.pop_back(); on_stk[x] = false;
                comp[x] = ccnt;
                if (x == u) break;
            }
            ++ccnt;
        }
    };
    for (int i = 0; i < n; ++i) if (tin[i] == -1) dfs(dfs, i);
    return {ccnt, std::move(comp)};
}

} // namespace codes_scc_condensation_d59
