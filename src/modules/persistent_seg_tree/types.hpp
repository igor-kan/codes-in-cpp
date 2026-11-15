#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_persistent_seg_tree {
struct PstNode {
    int left = -1;
    int right = -1;
    long long sum = 0;
};

struct PersistentSegTree {
    std::size_t n = 0;
    std::vector<PstNode> pool;
    std::vector<int> roots;
};
} // namespace codes_persistent_seg_tree
