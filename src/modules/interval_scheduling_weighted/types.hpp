#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_interval_scheduling_weighted {
struct WeightedJob {
    int64_t start = 0;
    int64_t finish = 0;
    int64_t weight = 0;
    std::size_t id = 0;
};

struct SchedulePlan {
    int64_t max_weight = 0;
    std::vector<std::size_t> selected_ids;
};
} // namespace codes_interval_scheduling_weighted
