#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_leftist_heap_d61 {
struct LeftistNode {
    std::int64_t key;
    int left;
    int right;
    int rank;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "leftist_heap_d61";
    int version = 1;
};
} // namespace codes_leftist_heap_d61
