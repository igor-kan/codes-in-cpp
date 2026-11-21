#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_floyd_warshall_min_cycle {

ApspOutcome floyd_warshall_solve(std::vector<std::vector<long long>> dist) {
    int n = static_cast<int>(dist.size());
    if (n == 0) throw std::invalid_argument("empty matrix");
    const long long INF = 1000000000000000LL;
    for (const auto& row : dist) {
        if (static_cast<int>(row.size()) != n) throw std::invalid_argument("matrix must be square");
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] >= INF / 2) continue;
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] >= INF / 2) continue;
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    bool neg = false;
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) neg = true;
    }
    return ApspOutcome{neg, std::move(dist)};
}

} // namespace codes_floyd_warshall_min_cycle
