#include "interface.hpp"

namespace codes_treap_implicit_rope {
Status validate_range(const ImplicitTreapArena& arena, std::size_t l, std::size_t r) {
    const std::size_t total = (arena.root < 0) ? 0 : arena.pool[static_cast<std::size_t>(arena.root)].sz;
    if (l > r || r > total) return Status::OutOfBounds;
    return Status::Ok;
}
} // namespace codes_treap_implicit_rope
