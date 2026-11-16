#include "interface.hpp"
#include <algorithm>

namespace codes_interval_scheduling_weighted {
int64_t max_weight_dp_fast(std::vector<WeightedJob> jobs) {
    if (validate_jobs(jobs) != Status::Ok) return 0;
    std::sort(jobs.begin(), jobs.end(), [](const WeightedJob& a, const WeightedJob& b) {
        return a.finish < b.finish;
    });
    const std::size_t n = jobs.size();
    std::vector<int64_t> finishes(n), dp(n + 1, 0);
    for (std::size_t i = 0; i < n; ++i) finishes[i] = jobs[i].finish;
    for (std::size_t i = 0; i < n; ++i) {
        auto it = std::upper_bound(finishes.begin(), finishes.begin() + static_cast<std::ptrdiff_t>(i), jobs[i].start);
        std::size_t p = static_cast<std::size_t>(it - finishes.begin());
        int64_t take = jobs[i].weight + dp[p];
        dp[i + 1] = std::max(dp[i], take);
    }
    return dp[n];
}
} // namespace codes_interval_scheduling_weighted
