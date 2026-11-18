#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_spfa_tarjan_neg_cycle {

std::vector<int> find_negative_cycle(int n, const std::vector<WEdge>& edges) {
    std::vector<std::int64_t> dist(n, 0);
    std::vector<int> par(n, -1);
    int x = -1;
    for (int step = 0; step < n; ++step) {
        x = -1;
        for (const auto& e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                par[e.v] = e.u;
                x = e.v;
            }
        }
        if (x == -1) return {};
    }
    for (int i = 0; i < n; ++i) x = par[x];
    std::vector<int> cyc;
    for (int cur = x;; cur = par[cur]) {
        cyc.push_back(cur);
        if (cur == x && cyc.size() > 1) break;
    }
    std::reverse(cyc.begin(), cyc.end());
    return cyc;
}

} // namespace codes_spfa_tarjan_neg_cycle
