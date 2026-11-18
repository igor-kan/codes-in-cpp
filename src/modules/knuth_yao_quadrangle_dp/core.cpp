#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_knuth_yao_quadrangle_dp {

ObstResult solve_obst_knuth(const std::vector<std::int64_t>& freq) {
    int n = static_cast<int>(freq.size());
    std::vector<std::int64_t> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + freq[i];
    auto wsum = [&](int l, int r) { return pref[r + 1] - pref[l]; };

    const std::int64_t INF = std::numeric_limits<std::int64_t>::max() / 4;
    std::vector<std::vector<std::int64_t>> dp(n, std::vector<std::int64_t>(n, 0));
    std::vector<std::vector<int>> opt(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) { dp[i][i] = freq[i]; opt[i][i] = i; }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp[i][j] = INF;
            int lo = opt[i][j - 1], hi = opt[i + 1][j];
            for (int r = lo; r <= hi; ++r) {
                std::int64_t left = (r > i) ? dp[i][r - 1] : 0;
                std::int64_t right = (r < j) ? dp[r + 1][j] : 0;
                std::int64_t cand = left + right + wsum(i, j);
                if (cand < dp[i][j]) { dp[i][j] = cand; opt[i][j] = r; }
            }
        }
    }
    return {dp[0][n - 1], opt[0][n - 1]};
}

} // namespace codes_knuth_yao_quadrangle_dp
