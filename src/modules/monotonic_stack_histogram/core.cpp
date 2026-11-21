#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_monotonic_stack_histogram {

long long largest_histogram_area(const std::vector<long long>& heights) {
    std::vector<int> stk;
    long long best = 0;
    int n = static_cast<int>(heights.size());
    for (int i = 0; i <= n; ++i) {
        long long cur = (i == n) ? 0LL : heights[i];
        if (cur < 0) throw std::invalid_argument("negative bar height");
        while (!stk.empty() && heights[stk.back()] > cur) {
            long long h = heights[stk.back()];
            stk.pop_back();
            long long left = stk.empty() ? -1LL : static_cast<long long>(stk.back());
            long long w = static_cast<long long>(i) - left - 1LL;
            best = std::max(best, h * w);
        }
        stk.push_back(i);
    }
    return best;
}

} // namespace codes_monotonic_stack_histogram
