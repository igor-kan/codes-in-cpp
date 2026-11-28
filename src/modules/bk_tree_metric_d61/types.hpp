#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_bk_tree_metric_d61 {
struct BkEdge {
    int distance;
    int child;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "bk_tree_metric_d61";
    int version = 1;
};
} // namespace codes_bk_tree_metric_d61
