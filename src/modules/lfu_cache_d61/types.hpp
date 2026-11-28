#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_lfu_cache_d61 {
struct LfuEntry {
    std::int64_t key;
    std::int64_t value;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "lfu_cache_d61";
    int version = 1;
};
} // namespace codes_lfu_cache_d61
