#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_eulerian_hierholzer_circuit {

std::vector<int> hierholzer_euler_circuit(int n, const std::vector<std::pair<int, int>>& edges) {
    if (n <= 0 || edges.empty()) throw std::invalid_argument("non-empty graph required");
    std::vector<std::vector<int>> adj(n);
    std::vector<int> indeg(n, 0), outdeg(n, 0);
    int start = edges[0].first;
    for (auto [u, v] : edges) {
        if (u < 0 || u >= n || v < 0 || v >= n) throw std::out_of_range("vertex out of range");
        adj[u].push_back(v);
        ++outdeg[u];
        ++indeg[v];
    }
    for (int i = 0; i < n; ++i) {
        if (indeg[i] != outdeg[i]) throw std::invalid_argument("degree balance violated");
    }
    std::vector<int> stk = {start};
    std::vector<int> path;
    path.reserve(edges.size() + 1);
    while (!stk.empty()) {
        int u = stk.back();
        if (!adj[u].empty()) {
            int nxt = adj[u].back();
            adj[u].pop_back();
            stk.push_back(nxt);
        } else {
            path.push_back(u);
            stk.pop_back();
        }
    }
    if (path.size() != edges.size() + 1) throw std::invalid_argument("graph is disconnected");
    std::reverse(path.begin(), path.end());
    return path;
}

} // namespace codes_eulerian_hierholzer_circuit
