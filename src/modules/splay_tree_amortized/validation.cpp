#include "interface.hpp"

namespace codes_splay_tree_amortized {
Status validate_tree_limits(const SplayTree& tree, std::size_t cap) {
    if (tree.pool.size() > cap) return Status::OutOfBounds;
    return Status::Ok;
}
} // namespace codes_splay_tree_amortized
