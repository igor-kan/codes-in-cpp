#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_scapegoat_weight_bst {
struct SgNode {
    std::int64_t key;
    int l = -1;
    int r = -1;
    int sz = 1;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "scapegoat_weight_bst";
    int version = 1;
};
} // namespace codes_scapegoat_weight_bst
