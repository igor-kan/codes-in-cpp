#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_z_algorithm_lcp_d60 {

std::vector<int> compute_z_array(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
std::vector<int> z_find_all(const std::string& text, const std::string& pat) {
    std::string combined = pat + "#" + text;
    auto z = compute_z_array(combined);
    int m = static_cast<int>(pat.size());
    std::vector<int> hits;
    for (int i = m + 1; i < static_cast<int>(combined.size()); ++i) {
        if (z[i] == m) hits.push_back(i - m - 1);
    }
    return hits;
}

} // namespace codes_z_algorithm_lcp_d60
