#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_dinic_level_flow_d57 {
struct DinicArc {
    int to = 0;
    int rev = 0;
    long long cap = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "dinic_level_flow_d57";
    int version = 1;
};
} // namespace codes_dinic_level_flow_d57
