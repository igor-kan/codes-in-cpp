#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_johnsons_reweight_apsp {

std::vector<std::vector<std::int64_t>> johnson_apsp(int n, const std::vector<WEdge>& edges) {
    const std::int64_t INF = std::numeric_limits<std::int64_t>::max() / 4;
    std::vector<std::int64_t> h(n, 0);
    for (int i = 0; i < n; ++i) {
        bool chg = false;
        for (const auto& e : edges) {
            if (h[e.u] + e.w < h[e.v]) { h[e.v] = h[e.u] + e.w; chg = true; }
        }
        if (!chg) break;
    }
    std::vector<std::vector<std::pair<int, std::int64_t>>> adj(n);
    for (const auto& e : edges) adj[e.u].push_back({e.v, e.w + h[e.u] - h[e.v]});
    std::vector<std::vector<std::int64_t>> all_d(n, std::vector<std::int64_t>(n, INF));
    for (int s = 0; s < n; ++s) {
        std::vector<std::int64_t> d(n, INF);
        d[s] = 0;
        using P = std::pair<std::int64_t, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [du, u] = pq.top(); pq.pop();
            if (du > d[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (du + w < d[v]) { d[v] = du + w; pq.push({d[v], v}); }
            }
        }
        for (int v = 0; v < n; ++v) if (d[v] < INF) all_d[s][v] = d[v] - h[s] + h[v];
    }
    return all_d;
}

} // namespace codes_johnsons_reweight_apsp
