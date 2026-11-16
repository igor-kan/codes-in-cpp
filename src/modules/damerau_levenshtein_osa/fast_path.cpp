#include "interface.hpp"
#include <algorithm>

namespace codes_damerau_levenshtein_osa {
std::size_t osa_rolling_fast(const std::string& a, const std::string& b) {
    const std::size_t m = a.size(), n = b.size();
    std::vector<std::size_t> prev2(n + 1, 0), prev1(n + 1, 0), cur(n + 1, 0);
    for (std::size_t j = 0; j <= n; ++j) prev1[j] = j;
    for (std::size_t i = 1; i <= m; ++i) {
        cur[0] = i;
        for (std::size_t j = 1; j <= n; ++j) {
            std::size_t cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            std::size_t best = std::min({prev1[j] + 1, cur[j - 1] + 1, prev1[j - 1] + cost});
            if (i > 1 && j > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1]) {
                best = std::min(best, prev2[j - 2] + 1);
            }
            cur[j] = best;
        }
        prev2.swap(prev1);
        prev1.swap(cur);
    }
    return prev1[n];
}
} // namespace codes_damerau_levenshtein_osa
