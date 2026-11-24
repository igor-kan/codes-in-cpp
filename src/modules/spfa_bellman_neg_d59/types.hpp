#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_spfa_bellman_neg_d59 {
struct SpfaEdge {
    int to = 0;
    long long w = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "spfa_bellman_neg_d59";
    int version = 1;
};
} // namespace codes_spfa_bellman_neg_d59
