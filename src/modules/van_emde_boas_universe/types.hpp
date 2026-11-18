#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_van_emde_boas_universe {
struct VebSummary {
    int min_v = -1;
    int max_v = -1;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "van_emde_boas_universe";
    int version = 1;
};
} // namespace codes_van_emde_boas_universe
