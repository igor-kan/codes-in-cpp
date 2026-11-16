#include "interface.hpp"

namespace codes_interval_scheduling_weighted {
Status validate_jobs(const std::vector<WeightedJob>& jobs) {
    if (jobs.empty()) return Status::NullOrEmpty;
    for (const auto& j : jobs) {
        if (j.start >= j.finish || j.weight < 0) return Status::InvalidInput;
    }
    return Status::Ok;
}
} // namespace codes_interval_scheduling_weighted
