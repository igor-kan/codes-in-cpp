#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_gaussian_elim_gf2_d58 {
struct XorBasisMeta {
    int rank = 0;
    uint64_t max_val = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "gaussian_elim_gf2_d58";
    int version = 1;
};
} // namespace codes_gaussian_elim_gf2_d58
