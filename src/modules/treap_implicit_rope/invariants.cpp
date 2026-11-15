#include "interface.hpp"

namespace codes_treap_implicit_rope {
Status verify_treap_invariants(const ImplicitTreapArena& arena, int t) {
    if (t < 0) return Status::Ok;
    const TreapNode& n = arena.pool[static_cast<std::size_t>(t)];
    std::size_t exp_sz = 1;
    long long exp_sum = n.val;
    if (n.left >= 0) {
        const TreapNode& lc = arena.pool[static_cast<std::size_t>(n.left)];
        if (lc.prio > n.prio) return Status::InvariantViolation;
        exp_sz += lc.sz;
        exp_sum += lc.sum;
        if (verify_treap_invariants(arena, n.left) != Status::Ok) return Status::InvariantViolation;
    }
    if (n.right >= 0) {
        const TreapNode& rc = arena.pool[static_cast<std::size_t>(n.right)];
        if (rc.prio > n.prio) return Status::InvariantViolation;
        exp_sz += rc.sz;
        exp_sum += rc.sum;
        if (verify_treap_invariants(arena, n.right) != Status::Ok) return Status::InvariantViolation;
    }
    if (n.sz != exp_sz || n.sum != exp_sum) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_treap_implicit_rope
