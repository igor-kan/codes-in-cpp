#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_hungarian_min_assign_cpp {

AssignRes hungarian_min_cost(const std::vector<std::vector<std::int64_t>>& cost) {
    int n = static_cast<int>(cost.size());
    const std::int64_t INF = std::numeric_limits<std::int64_t>::max() / 4;
    std::vector<std::int64_t> u(n + 1, 0), v(n + 1, 0);
    std::vector<int> p(n + 1, 0), way(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        std::vector<std::int64_t> minv(n + 1, INF);
        std::vector<bool> used(n + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], j1 = 0;
            std::int64_t delta = INF;
            for (int j = 1; j <= n; ++j) if (!used[j]) {
                std::int64_t cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < minv[j]) { minv[j] = cur; way[j] = j0; }
                if (minv[j] < delta) { delta = minv[j]; j1 = j; }
            }
            for (int j = 0; j <= n; ++j) {
                if (used[j]) { u[p[j]] += delta; v[j] -= delta; }
                else minv[j] -= delta;
            }
            j0 = j1;
        } while (p[j0] != 0);
        do { int j1 = way[j0]; p[j0] = p[j1]; j0 = j1; } while (j0);
    }
    std::vector<int> ans(n);
    for (int j = 1; j <= n; ++j) ans[p[j] - 1] = j - 1;
    return {-v[0], ans};
}

} // namespace codes_hungarian_min_assign_cpp
