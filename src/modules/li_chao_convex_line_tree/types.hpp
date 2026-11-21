#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_li_chao_convex_line_tree {
struct LinearFn {
    long long m = 0;
    long long b = 1000000000000000000LL;
    long long eval(long long x) const { return m * x + b; }
};

struct ModuleMeta {
    static constexpr const char* kSlug = "li_chao_convex_line_tree";
    int version = 1;
};
} // namespace codes_li_chao_convex_line_tree
