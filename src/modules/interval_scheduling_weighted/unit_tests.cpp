#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_interval_scheduling_weighted;
    std::vector<WeightedJob> jobs = {
        {1, 4, 5, 0}, {3, 5, 1, 1}, {0, 6, 8, 2}, {4, 7, 4, 3}, {3, 8, 6, 4}, {5, 9, 3, 5}, {6, 10, 2, 6}, {8, 11, 4, 7}
    };
    auto plan = solve_weighted_intervals(jobs);
    assert(plan.max_weight == 13);
    assert(max_weight_dp_fast(jobs) == 13);
    assert(verify_schedule_invariants(jobs, plan) == Status::Ok);
    return 0;
}
