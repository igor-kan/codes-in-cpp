#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_graham_scan_hull_d58 {
struct PolyMetrics {
    int hull_size = 0;
    long long area2 = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "graham_scan_hull_d58";
    int version = 1;
};
} // namespace codes_graham_scan_hull_d58
