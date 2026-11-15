#include "interface.hpp"
#include <algorithm>
#include <limits>

namespace codes_hungarian_kuhn_munkres {
AssignmentResult solve_hungarian(std::size_t rows, std::size_t cols, const std::vector<long long>& cost_matrix) {
    const long long INF = std::numeric_limits<long long>::max() / 4;
    std::vector<long long> u(rows + 1, 0), v(cols + 1, 0);
    std::vector<std::size_t> p(cols + 1, 0), way(cols + 1, 0);

    for (std::size_t i = 1; i <= rows; ++i) {
        p[0] = i;
        std::size_t j0 = 0;
        std::vector<long long> minv(cols + 1, INF);
        std::vector<bool> used(cols + 1, false);
        do {
            used[j0] = true;
            std::size_t i0 = p[j0];
            long long delta = INF;
            std::size_t j1 = 0;
            for (std::size_t j = 1; j <= cols; ++j) {
                if (!used[j]) {
                    long long cur = cost_matrix[(i0 - 1) * cols + (j - 1)] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (std::size_t j = 0; j <= cols; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            std::size_t j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    AssignmentResult res;
    res.col_for_row.assign(rows, 0);
    for (std::size_t j = 1; j <= cols; ++j) {
        if (p[j] > 0) res.col_for_row[p[j] - 1] = j - 1;
    }
    res.min_cost = -v[0];
    res.dual_bound = -v[0];
    return res;
}
} // namespace codes_hungarian_kuhn_munkres
