#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_kmp_cyclic_period_d59 {

int shortest_exact_period(const std::string& s) {
    if (s.empty()) return 0;
    int n = static_cast<int>(s.size());
    std::vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    int cand = n - pi[n - 1];
    return (n % cand == 0) ? cand : n;
}

} // namespace codes_kmp_cyclic_period_d59
