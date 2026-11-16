#include "interface.hpp"
#include <algorithm>
#include <unordered_map>

namespace codes_interval_scheduling_weighted {
Status verify_schedule_invariants(const std::vector<WeightedJob>& jobs, const SchedulePlan& plan) {
    if (validate_jobs(jobs) != Status::Ok) return Status::InvalidInput;
    std::unordered_map<std::size_t, WeightedJob> by_id;
    for (const auto& j : jobs) by_id[j.id] = j;
    std::vector<WeightedJob> picked;
    int64_t sum = 0;
    for (std::size_t id : plan.selected_ids) {
        auto it = by_id.find(id);
        if (it == by_id.end()) return Status::InvariantViolation;
        picked.push_back(it->second);
        sum += it->second.weight;
    }
    if (sum != plan.max_weight) return Status::InvariantViolation;
    std::sort(picked.begin(), picked.end(), [](const WeightedJob& a, const WeightedJob& b) {
        return a.start < b.start;
    });
    for (std::size_t i = 1; i < picked.size(); ++i) {
        if (picked[i - 1].finish > picked[i].start) return Status::InvariantViolation;
    }
    return Status::Ok;
}
} // namespace codes_interval_scheduling_weighted
