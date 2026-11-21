#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_monotonic_stack_histogram {
struct HistBar {
    int index = 0;
    long long height = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "monotonic_stack_histogram";
    int version = 1;
};
} // namespace codes_monotonic_stack_histogram
