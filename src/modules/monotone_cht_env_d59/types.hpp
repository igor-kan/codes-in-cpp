#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_monotone_cht_env_d59 {
struct ChtLine {
    long long m = 0;
    long long b = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "monotone_cht_env_d59";
    int version = 1;
};
} // namespace codes_monotone_cht_env_d59
