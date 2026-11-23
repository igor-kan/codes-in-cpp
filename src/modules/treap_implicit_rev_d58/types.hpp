#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_treap_implicit_rev_d58 {
struct SliceOp {
    int l = 0;
    int r = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "treap_implicit_rev_d58";
    int version = 1;
};
} // namespace codes_treap_implicit_rev_d58
