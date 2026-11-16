#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_interval_scheduling_weighted {
std::vector<SchedulePlan> batch_schedule_plans(const std::vector<std::vector<WeightedJob>>& suites) {
    std::vector<SchedulePlan> out(suites.size());
    if (suites.empty()) return out;
    std::size_t nt = std::min<std::size_t>(4, suites.size());
    std::vector<std::thread> pool;
    for (std::size_t t = 0; t < nt; ++t) {
        pool.emplace_back([&, t]() {
            for (std::size_t i = t; i < suites.size(); i += nt) {
                out[i] = solve_weighted_intervals(suites[i]);
            }
        });
    }
    for (auto& th : pool) th.join();
    return out;
}
} // namespace codes_interval_scheduling_weighted
