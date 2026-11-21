#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_bridges_tarjan_lowlink {
struct GraphEdgePair {
    int u = 0;
    int v = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "bridges_tarjan_lowlink";
    int version = 1;
};
} // namespace codes_bridges_tarjan_lowlink
