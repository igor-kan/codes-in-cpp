#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_suffix_array_doubling_d57 {
struct SuffixRankEntry {
    int idx = 0;
    int r0 = 0;
    int r1 = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "suffix_array_doubling_d57";
    int version = 1;
};
} // namespace codes_suffix_array_doubling_d57
