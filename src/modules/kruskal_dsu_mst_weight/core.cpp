#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_kruskal_dsu_mst_weight {

std::pair<long long, int> kruskal_mst(int n, std::vector<WeightedLink> edges) {
    if (n <= 0) throw std::invalid_argument("n must be positive");
    std::sort(edges.begin(), edges.end(), [](const WeightedLink& a, const WeightedLink& b) {
        return a.w < b.w;
    });
    std::vector<int> parent(n), rnk(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;
    auto find = [&](int x) -> int {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };
    long long total = 0;
    int picked = 0;
    for (const auto& e : edges) {
        if (e.u < 0 || e.u >= n || e.v < 0 || e.v >= n) throw std::out_of_range("vertex index out of range");
        int ru = find(e.u);
        int rv = find(e.v);
        if (ru != rv) {
            if (rnk[ru] < rnk[rv]) std::swap(ru, rv);
            parent[rv] = ru;
            if (rnk[ru] == rnk[rv]) ++rnk[ru];
            total += e.w;
            ++picked;
        }
    }
    return {total, picked};
}

} // namespace codes_kruskal_dsu_mst_weight
