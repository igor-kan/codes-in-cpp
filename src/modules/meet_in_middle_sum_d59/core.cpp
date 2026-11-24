#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_meet_in_middle_sum_d59 {

bool subset_sum_mim(const std::vector<long long>& xs, long long target) {
    int n = static_cast<int>(xs.size());
    int mid = n / 2;
    auto gen = [&](int l, int r) {
        std::vector<long long> sums = {0};
        for (int i = l; i < r; ++i) {
            std::size_t sz = sums.size();
            for (std::size_t k = 0; k < sz; ++k) sums.push_back(sums[k] + xs[i]);
        }
        return sums;
    };
    auto left = gen(0, mid);
    auto right = gen(mid, n);
    std::sort(right.begin(), right.end());
    for (long long v : left) {
        if (std::binary_search(right.begin(), right.end(), target - v)) return true;
    }
    return false;
}

} // namespace codes_meet_in_middle_sum_d59
