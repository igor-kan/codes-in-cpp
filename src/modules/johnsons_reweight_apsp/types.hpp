#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_johnsons_reweight_apsp {
struct WEdge {
    int u = 0;
    int v = 0;
    std::int64_t w = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "johnsons_reweight_apsp";
    int version = 1;
};
} // namespace codes_johnsons_reweight_apsp
