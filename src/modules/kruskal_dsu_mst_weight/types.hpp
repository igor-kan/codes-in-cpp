#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_kruskal_dsu_mst_weight {
struct WeightedLink {
    int u = 0;
    int v = 0;
    long long w = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "kruskal_dsu_mst_weight";
    int version = 1;
};
} // namespace codes_kruskal_dsu_mst_weight
