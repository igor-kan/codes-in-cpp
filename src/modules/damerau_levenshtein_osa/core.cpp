#include "interface.hpp"
#include <algorithm>
#include <array>

namespace codes_damerau_levenshtein_osa {
std::size_t optimal_string_alignment(const std::string& a, const std::string& b) {
    const std::size_t m = a.size(), n = b.size();
    std::vector<std::vector<std::size_t>> dp(m + 1, std::vector<std::size_t>(n + 1, 0));
    for (std::size_t i = 0; i <= m; ++i) dp[i][0] = i;
    for (std::size_t j = 0; j <= n; ++j) dp[0][j] = j;
    for (std::size_t i = 1; i <= m; ++i) {
        for (std::size_t j = 1; j <= n; ++j) {
            std::size_t cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            std::size_t best = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
            if (i > 1 && j > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1]) {
                best = std::min(best, dp[i - 2][j - 2] + 1);
            }
            dp[i][j] = best;
        }
    }
    return dp[m][n];
}

std::size_t true_damerau_levenshtein(const std::string& a, const std::string& b) {
    const std::size_t m = a.size(), n = b.size();
    const std::size_t maxdist = m + n;
    std::vector<std::vector<std::size_t>> d(m + 2, std::vector<std::size_t>(n + 2, maxdist));
    d[1][1] = 0;
    for (std::size_t i = 0; i <= m; ++i) d[i + 1][1] = i;
    for (std::size_t j = 0; j <= n; ++j) d[1][j + 1] = j;
    std::array<std::size_t, 256> da{};
    for (std::size_t i = 1; i <= m; ++i) {
        std::size_t db = 0;
        for (std::size_t j = 1; j <= n; ++j) {
            std::size_t i1 = da[static_cast<unsigned char>(b[j - 1])];
            std::size_t j1 = db;
            std::size_t cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            if (cost == 0) db = j;
            std::size_t cand_swap = d[i1][j1] + (i - i1 - 1) + 1 + (j - j1 - 1);
            d[i + 1][j + 1] = std::min({
                d[i][j] + cost,
                d[i + 1][j] + 1,
                d[i][j + 1] + 1,
                cand_swap
            });
        }
        da[static_cast<unsigned char>(a[i - 1])] = i;
    }
    return d[m + 1][n + 1];
}
} // namespace codes_damerau_levenshtein_osa
