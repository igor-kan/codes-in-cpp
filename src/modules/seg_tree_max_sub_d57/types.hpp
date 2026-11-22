#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_seg_tree_max_sub_d57 {
struct MaxSubNode {
    long long sum = 0;
    long long pref = 0;
    long long suff = 0;
    long long best = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "seg_tree_max_sub_d57";
    int version = 1;
};
} // namespace codes_seg_tree_max_sub_d57
