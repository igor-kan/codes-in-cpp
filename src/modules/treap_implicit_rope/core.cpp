#include "interface.hpp"
#include <utility>

namespace codes_treap_implicit_rope {
std::uint64_t next_prio(ImplicitTreapArena& arena) {
    arena.rng += 0x9e3779b97f4a7c15ULL;
    std::uint64_t z = arena.rng;
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}

int new_node(ImplicitTreapArena& arena, long long val) {
    TreapNode n;
    n.prio = next_prio(arena);
    n.val = val;
    n.sum = val;
    n.sz = 1;
    int id = static_cast<int>(arena.pool.size());
    arena.pool.push_back(n);
    return id;
}

static std::size_t node_sz(const ImplicitTreapArena& a, int t) {
    return (t < 0) ? 0 : a.pool[static_cast<std::size_t>(t)].sz;
}

static long long node_sum(const ImplicitTreapArena& a, int t) {
    return (t < 0) ? 0LL : a.pool[static_cast<std::size_t>(t)].sum;
}

void push_down(ImplicitTreapArena& arena, int t) {
    if (t < 0) return;
    TreapNode& n = arena.pool[static_cast<std::size_t>(t)];
    if (!n.rev) return;
    std::swap(n.left, n.right);
    if (n.left >= 0) arena.pool[static_cast<std::size_t>(n.left)].rev ^= true;
    if (n.right >= 0) arena.pool[static_cast<std::size_t>(n.right)].rev ^= true;
    n.rev = false;
}

void pull_up(ImplicitTreapArena& arena, int t) {
    if (t < 0) return;
    TreapNode& n = arena.pool[static_cast<std::size_t>(t)];
    n.sz = 1 + node_sz(arena, n.left) + node_sz(arena, n.right);
    n.sum = n.val + node_sum(arena, n.left) + node_sum(arena, n.right);
}

void split_by_index(ImplicitTreapArena& arena, int t, std::size_t k, int& left_out, int& right_out) {
    if (t < 0) { left_out = -1; right_out = -1; return; }
    push_down(arena, t);
    const std::size_t lsz = node_sz(arena, arena.pool[static_cast<std::size_t>(t)].left);
    if (k <= lsz) {
        int lsub = -1, rsub = -1;
        int lc = arena.pool[static_cast<std::size_t>(t)].left;
        split_by_index(arena, lc, k, lsub, rsub);
        arena.pool[static_cast<std::size_t>(t)].left = rsub;
        pull_up(arena, t);
        left_out = lsub;
        right_out = t;
    } else {
        int lsub = -1, rsub = -1;
        int rc = arena.pool[static_cast<std::size_t>(t)].right;
        split_by_index(arena, rc, k - lsz - 1, lsub, rsub);
        arena.pool[static_cast<std::size_t>(t)].right = lsub;
        pull_up(arena, t);
        left_out = t;
        right_out = rsub;
    }
}

int merge_treaps(ImplicitTreapArena& arena, int l, int r) {
    if (l < 0) return r;
    if (r < 0) return l;
    push_down(arena, l);
    push_down(arena, r);
    if (arena.pool[static_cast<std::size_t>(l)].prio >= arena.pool[static_cast<std::size_t>(r)].prio) {
        int nr = merge_treaps(arena, arena.pool[static_cast<std::size_t>(l)].right, r);
        arena.pool[static_cast<std::size_t>(l)].right = nr;
        pull_up(arena, l);
        return l;
    } else {
        int nl = merge_treaps(arena, l, arena.pool[static_cast<std::size_t>(r)].left);
        arena.pool[static_cast<std::size_t>(r)].left = nl;
        pull_up(arena, r);
        return r;
    }
}

void insert_at(ImplicitTreapArena& arena, std::size_t idx, long long val) {
    int l = -1, r = -1;
    split_by_index(arena, arena.root, idx, l, r);
    int mid = new_node(arena, val);
    arena.root = merge_treaps(arena, merge_treaps(arena, l, mid), r);
}

void reverse_range(ImplicitTreapArena& arena, std::size_t l, std::size_t r) {
    if (l >= r) return;
    int t1 = -1, t2 = -1, t3 = -1;
    split_by_index(arena, arena.root, l, t1, t2);
    split_by_index(arena, t2, r - l, t2, t3);
    if (t2 >= 0) arena.pool[static_cast<std::size_t>(t2)].rev ^= true;
    arena.root = merge_treaps(arena, merge_treaps(arena, t1, t2), t3);
}

long long query_sum(ImplicitTreapArena& arena, std::size_t l, std::size_t r) {
    if (l >= r) return 0;
    int t1 = -1, t2 = -1, t3 = -1;
    split_by_index(arena, arena.root, l, t1, t2);
    split_by_index(arena, t2, r - l, t2, t3);
    long long ans = node_sum(arena, t2);
    arena.root = merge_treaps(arena, merge_treaps(arena, t1, t2), t3);
    return ans;
}

void to_vector(ImplicitTreapArena& arena, int t, std::vector<long long>& out) {
    if (t < 0) return;
    push_down(arena, t);
    const TreapNode n = arena.pool[static_cast<std::size_t>(t)];
    to_vector(arena, n.left, out);
    out.push_back(n.val);
    to_vector(arena, n.right, out);
}
} // namespace codes_treap_implicit_rope
