#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_sos_dp_subset_convolution {
struct HypercubeSpec {
    int bits = 0;
    std::size_t size = 1;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "sos_dp_subset_convolution";
    int version = 1;
};
} // namespace codes_sos_dp_subset_convolution
