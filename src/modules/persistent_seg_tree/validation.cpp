#include "interface.hpp"

namespace codes_persistent_seg_tree {
Status validate_version_query(const PersistentSegTree& pst, std::size_t ver, std::size_t l, std::size_t r) {
    if (pst.n == 0) return Status::NullOrEmpty;
    if (ver >= pst.roots.size() || l > r || r >= pst.n) return Status::OutOfBounds;
    return Status::Ok;
}
} // namespace codes_persistent_seg_tree
