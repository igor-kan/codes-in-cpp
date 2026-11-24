#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_scc_condensation_d59 {
struct SccSummary {
    int comp_count = 0;
    std::vector<int> comp_id;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "scc_condensation_d59";
    int version = 1;
};
} // namespace codes_scc_condensation_d59
