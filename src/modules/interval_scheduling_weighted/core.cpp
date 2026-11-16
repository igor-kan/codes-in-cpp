#include "interface.hpp"
#include <algorithm>

namespace codes_interval_scheduling_weighted {
SchedulePlan solve_weighted_intervals(std::vector<WeightedJob> jobs) {
    SchedulePlan plan{};
    if (validate_jobs(jobs) != Status::Ok) return plan;
    std::sort(jobs.begin(), jobs.end(), [](const WeightedJob& a, const WeightedJob& b) {
        return a.finish < b.finish;
    });
    const std::size_t n = jobs.size();
    std::vector<int> prev_compat(n, -1);
    for (std::size_t i = 0; i < n; ++i) {
        auto it = std::upper_bound(jobs.begin(), jobs.begin() + static_cast<std::ptrdiff_t>(i), jobs[i].start,
                                   [](int64_t s, const WeightedJob& j) { return s < j.finish; });
        if (it != jobs.begin()) prev_compat[i] = static_cast<int>(it - jobs.begin()) - 1;
    }
    std::vector<int64_t> dp(n + 1, 0);
    std::vector<bool> pick(n, false);
    for (std::size_t i = 0; i < n; ++i) {
        int64_t take = jobs[i].weight + (prev_compat[i] >= 0 ? dp[static_cast<std::size_t>(prev_compat[i]) + 1] : 0);
        int64_t skip = dp[i];
        if (take > skip) { dp[i + 1] = take; pick[i] = true; }
        else { dp[i + 1] = skip; pick[i] = false; }
    }
    plan.max_weight = dp[n];
    int cur = static_cast<int>(n) - 1;
    while (cur >= 0) {
        std::size_t uc = static_cast<std::size_t>(cur);
        if (pick[uc]) {
            plan.selected_ids.push_back(jobs[uc].id);
            cur = prev_compat[uc];
        } else {
            --cur;
        }
    }
    std::reverse(plan.selected_ids.begin(), plan.selected_ids.end());
    return plan;
}
} // namespace codes_interval_scheduling_weighted
