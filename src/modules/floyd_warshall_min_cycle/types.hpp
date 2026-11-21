#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_floyd_warshall_min_cycle {
struct ApspOutcome {
    bool has_negative_cycle = false;
    std::vector<std::vector<long long>> dist;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "floyd_warshall_min_cycle";
    int version = 1;
};
} // namespace codes_floyd_warshall_min_cycle
