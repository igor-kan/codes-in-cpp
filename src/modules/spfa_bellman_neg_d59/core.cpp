#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_spfa_bellman_neg_d59 {

std::pair<bool, std::vector<long long>> spfa_distances(int n, int src, const std::vector<std::vector<SpfaEdge>>& adj) {
    const long long INF = 1000000000000000LL;
    std::vector<long long> dist(n, INF);
    std::vector<int> cnt(n, 0);
    std::vector<bool> inq(n, false);
    std::deque<int> q = {src};
    dist[src] = 0; inq[src] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop_front(); inq[u] = false;
        for (const auto& e : adj[u]) {
            if (dist[u] + e.w < dist[e.to]) {
                dist[e.to] = dist[u] + e.w;
                cnt[e.to] = cnt[u] + 1;
                if (cnt[e.to] >= n) return {true, dist};
                if (!inq[e.to]) { q.push_back(e.to); inq[e.to] = true; }
            }
        }
    }
    return {false, dist};
}

} // namespace codes_spfa_bellman_neg_d59
