#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_li_chao_segment_lines {
struct AffineLine {
    std::int64_t m = 0;
    std::int64_t b = 4000000000000000000LL;
    std::int64_t eval(std::int64_t x) const { return m * x + b; }
};

struct ModuleMeta {
    static constexpr const char* kSlug = "li_chao_segment_lines";
    int version = 1;
};
} // namespace codes_li_chao_segment_lines
