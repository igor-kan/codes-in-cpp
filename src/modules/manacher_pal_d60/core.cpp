#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_manacher_pal_d60 {

std::vector<int> odd_radii_d60(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> d1(n, 0);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) ++k;
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return d1;
}
PalSpan longest_palindrome_d60(const std::string& s) {
    int n = static_cast<int>(s.size());
    if (n == 0) return {0, 0};
    auto d1 = odd_radii_d60(s);
    std::vector<int> d2(n, 0);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = (i > r) ? 0 : std::min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) ++k;
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    int best_st = 0, best_len = 1;
    for (int i = 0; i < n; ++i) {
        int len1 = 2 * d1[i] - 1;
        if (len1 > best_len) { best_len = len1; best_st = i - d1[i] + 1; }
        int len2 = 2 * d2[i];
        if (len2 > best_len) { best_len = len2; best_st = i - d2[i]; }
    }
    return {best_st, best_len};
}

} // namespace codes_manacher_pal_d60
