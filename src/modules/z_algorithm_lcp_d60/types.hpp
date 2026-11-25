#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_z_algorithm_lcp_d60 {
struct ZMatch {
    int pos;
    int len;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "z_algorithm_lcp_d60";
    int version = 1;
};
} // namespace codes_z_algorithm_lcp_d60
