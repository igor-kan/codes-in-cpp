#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_persistent_segtree_kth {
struct PSegNode {
    int l = 0;
    int r = 0;
    int cnt = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "persistent_segtree_kth";
    int version = 1;
};
} // namespace codes_persistent_segtree_kth
