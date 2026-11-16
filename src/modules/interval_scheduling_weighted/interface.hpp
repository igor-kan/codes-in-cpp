#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_interval_scheduling_weighted {
SchedulePlan solve_weighted_intervals(std::vector<WeightedJob> jobs);
Status validate_jobs(const std::vector<WeightedJob>& jobs);
int64_t max_weight_dp_fast(std::vector<WeightedJob> jobs);
std::vector<SchedulePlan> batch_schedule_plans(const std::vector<std::vector<WeightedJob>>& suites);
Status verify_schedule_invariants(const std::vector<WeightedJob>& jobs, const SchedulePlan& plan);
} // namespace codes_interval_scheduling_weighted
