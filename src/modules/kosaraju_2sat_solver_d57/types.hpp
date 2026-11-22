#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_kosaraju_2sat_solver_d57 {
struct SatClause {
    int a = 0;
    bool neg_a = false;
    int b = 0;
    bool neg_b = false;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "kosaraju_2sat_solver_d57";
    int version = 1;
};
} // namespace codes_kosaraju_2sat_solver_d57
