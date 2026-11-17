#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_skiplist_index_cpp {
constexpr int SL_MAX_LEVEL = 12;
struct SkipNode {
    std::int64_t key = 0;
    std::int64_t val = 0;
    std::array<int, SL_MAX_LEVEL> next{};
    int height = 1;
};
} // namespace codes_skiplist_index_cpp
