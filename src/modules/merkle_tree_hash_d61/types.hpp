#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_merkle_tree_hash_d61 {
struct MerkleProofStep {
    std::uint64_t sibling;
    bool is_left;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "merkle_tree_hash_d61";
    int version = 1;
};
} // namespace codes_merkle_tree_hash_d61
