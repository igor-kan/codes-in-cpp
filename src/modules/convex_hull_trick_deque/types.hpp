#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_convex_hull_trick_deque {
struct ChtLine {
    std::int64_t m = 0;
    std::int64_t b = 0;
    std::int64_t eval(std::int64_t x) const { return m * x + b; }
};

struct ModuleMeta {
    static constexpr const char* kSlug = "convex_hull_trick_deque";
    int version = 1;
};
} // namespace codes_convex_hull_trick_deque
