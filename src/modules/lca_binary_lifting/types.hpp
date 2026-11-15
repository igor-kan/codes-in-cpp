#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_lca_binary_lifting {
struct LcaIndex {
    std::size_t n = 0;
    std::size_t log_n = 0;
    std::size_t root = 0;
    std::vector<std::size_t> depth;
    std::vector<std::size_t> tin;
    std::vector<std::size_t> tout;
    std::vector<std::size_t> up; // flat [k * n + u]
};
} // namespace codes_lca_binary_lifting
