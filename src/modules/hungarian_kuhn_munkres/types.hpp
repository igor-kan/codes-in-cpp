#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_hungarian_kuhn_munkres {
struct AssignmentResult {
    long long min_cost = 0;
    std::vector<std::size_t> col_for_row;
    long long dual_bound = 0;
};
} // namespace codes_hungarian_kuhn_munkres
