#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_manacher_pal_d60 {
struct PalSpan {
    int start;
    int length;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "manacher_pal_d60";
    int version = 1;
};
} // namespace codes_manacher_pal_d60
