#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_hungarian_min_assign_cpp {
struct AssignRes {
    std::int64_t total_cost = 0;
    std::vector<int> col_for_row;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "hungarian_min_assign_cpp";
    int version = 1;
};
} // namespace codes_hungarian_min_assign_cpp
