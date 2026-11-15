#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_splay_tree_amortized {
struct SplayNode {
    long long key = 0;
    int parent = -1;
    int ch[2] = {-1, -1};
    std::size_t sz = 1;
};

struct SplayTree {
    std::vector<SplayNode> pool;
    int root = -1;
};
} // namespace codes_splay_tree_amortized
