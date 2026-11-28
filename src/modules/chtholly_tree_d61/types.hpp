#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_chtholly_tree_d61 {
struct IntervalNode {
    int l;
    int r;
    std::int64_t val;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "chtholly_tree_d61";
    int version = 1;
};
} // namespace codes_chtholly_tree_d61
