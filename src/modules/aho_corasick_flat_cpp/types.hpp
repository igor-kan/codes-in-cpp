#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_aho_corasick_flat_cpp {
struct FlatAcNode {
    std::array<int, 26> next{};
    int fail = 0;
    int out_count = 0;
};
} // namespace codes_aho_corasick_flat_cpp
