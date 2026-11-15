#include "interface.hpp"

namespace codes_treap_implicit_rope {
static void heapify_down(ImplicitTreapArena& a, int t) {
    while (t >= 0) {
        int max_id = t;
        int l = a.pool[static_cast<std::size_t>(t)].left;
        int r = a.pool[static_cast<std::size_t>(t)].right;
        if (l >= 0 && a.pool[static_cast<std::size_t>(l)].prio > a.pool[static_cast<std::size_t>(max_id)].prio) max_id = l;
        if (r >= 0 && a.pool[static_cast<std::size_t>(r)].prio > a.pool[static_cast<std::size_t>(max_id)].prio) max_id = r;
        if (max_id == t) break;
        std::swap(a.pool[static_cast<std::size_t>(t)].prio, a.pool[static_cast<std::size_t>(max_id)].prio);
        t = max_id;
    }
}

static int build_rec(ImplicitTreapArena& a, const std::vector<long long>& vals, std::size_t l, std::size_t r) {
    if (l >= r) return -1;
    std::size_t mid = l + (r - l) / 2;
    int t = new_node(a, vals[mid]);
    int lc = build_rec(a, vals, l, mid);
    int rc = build_rec(a, vals, mid + 1, r);
    a.pool[static_cast<std::size_t>(t)].left = lc;
    a.pool[static_cast<std::size_t>(t)].right = rc;
    heapify_down(a, t);
    pull_up(a, t);
    return t;
}

void build_linear_fast(ImplicitTreapArena& arena, const std::vector<long long>& vals) {
    arena.pool.clear();
    arena.pool.reserve(vals.size());
    arena.root = build_rec(arena, vals, 0, vals.size());
}
} // namespace codes_treap_implicit_rope
