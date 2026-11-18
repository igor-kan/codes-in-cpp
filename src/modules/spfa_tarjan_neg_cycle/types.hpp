#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_spfa_tarjan_neg_cycle {
struct WEdge {
    int u;
    int v;
    std::int64_t w;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "spfa_tarjan_neg_cycle";
    int version = 1;
};
} // namespace codes_spfa_tarjan_neg_cycle
