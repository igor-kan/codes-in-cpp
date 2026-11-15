#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_treap_implicit_rope {
struct TreapNode {
    std::uint64_t prio = 0;
    long long val = 0;
    long long sum = 0;
    std::size_t sz = 1;
    bool rev = false;
    int left = -1;
    int right = -1;
};

struct ImplicitTreapArena {
    std::vector<TreapNode> pool;
    int root = -1;
    std::uint64_t rng = 0x9e3779b97f4a7c15ULL;
};
} // namespace codes_treap_implicit_rope
