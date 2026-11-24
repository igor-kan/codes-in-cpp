#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_kmp_cyclic_period_d59 {
struct PeriodMeta {
    int length = 0;
    int min_period = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "kmp_cyclic_period_d59";
    int version = 1;
};
} // namespace codes_kmp_cyclic_period_d59
