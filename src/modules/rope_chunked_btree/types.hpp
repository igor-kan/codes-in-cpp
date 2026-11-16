#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_rope_chunked_btree {
struct RopeNode {
    std::size_t total_len = 0;
    std::size_t left_weight = 0;
    std::string chunk;
    int left = -1;
    int right = -1;
};

struct RopeStore {
    std::vector<RopeNode> pool;
    int root = -1;
};
} // namespace codes_rope_chunked_btree
