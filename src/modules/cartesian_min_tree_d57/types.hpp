#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_cartesian_min_tree_d57 {
struct CartNode {
    long long val = 0;
    int left = -1;
    int right = -1;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "cartesian_min_tree_d57";
    int version = 1;
};
} // namespace codes_cartesian_min_tree_d57
