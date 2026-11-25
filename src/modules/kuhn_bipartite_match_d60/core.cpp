#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_kuhn_bipartite_match_d60 {

int kuhn_max_matching(int nl, int nr, const std::vector<BipartiteEdge>& edges) {
    std::vector<std::vector<int>> adj(nl);
    for (const auto& e : edges) {
        if (e.left >= 0 && e.left < nl && e.right >= 0 && e.right < nr) {
            adj[e.left].push_back(e.right);
        }
    }
    std::vector<int> match_r(nr, -1);
    std::vector<int> vis(nl, 0);
    int epoch = 0;
    auto dfs = [&](auto& self, int u) -> bool {
        if (vis[u] == epoch) return false;
        vis[u] = epoch;
        for (int v : adj[u]) {
            if (match_r[v] == -1 || self(self, match_r[v])) {
                match_r[v] = u;
                return true;
            }
        }
        return false;
    };
    int ans = 0;
    for (int u = 0; u < nl; ++u) {
        ++epoch;
        if (dfs(dfs, u)) ++ans;
    }
    return ans;
}

} // namespace codes_kuhn_bipartite_match_d60
