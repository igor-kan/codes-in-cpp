#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_palindromic_tree_eertree {
struct EertreeNode {
    int len = 0;
    int link = 0;
    int next[26];
    EertreeNode(int l = 0, int lk = 0) : len(l), link(lk) {
        std::fill(std::begin(next), std::end(next), -1);
    }
};

struct ModuleMeta {
    static constexpr const char* kSlug = "palindromic_tree_eertree";
    int version = 1;
};
} // namespace codes_palindromic_tree_eertree
