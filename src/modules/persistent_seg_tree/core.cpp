#include "interface.hpp"

namespace codes_persistent_seg_tree {
static int build_pst(PersistentSegTree& pst, const std::vector<long long>& a, std::size_t l, std::size_t r) {
    int id = static_cast<int>(pst.pool.size());
    pst.pool.push_back(PstNode{});
    if (l == r) {
        pst.pool[static_cast<std::size_t>(id)].sum = a[l];
        return id;
    }
    std::size_t m = l + (r - l) / 2;
    int lc = build_pst(pst, a, l, m);
    int rc = build_pst(pst, a, m + 1, r);
    pst.pool[static_cast<std::size_t>(id)].left = lc;
    pst.pool[static_cast<std::size_t>(id)].right = rc;
    pst.pool[static_cast<std::size_t>(id)].sum = pst.pool[static_cast<std::size_t>(lc)].sum + pst.pool[static_cast<std::size_t>(rc)].sum;
    return id;
}

PersistentSegTree pst_create(const std::vector<long long>& init_vals) {
    PersistentSegTree pst;
    pst.n = init_vals.size();
    if (pst.n > 0) {
        pst.pool.reserve(pst.n * 4);
        pst.roots.push_back(build_pst(pst, init_vals, 0, pst.n - 1));
    }
    return pst;
}

static int clone_update(PersistentSegTree& pst, int prev, std::size_t l, std::size_t r, std::size_t pos, long long delta) {
    int cur = static_cast<int>(pst.pool.size());
    pst.pool.push_back(pst.pool[static_cast<std::size_t>(prev)]);
    if (l == r) {
        pst.pool[static_cast<std::size_t>(cur)].sum += delta;
        return cur;
    }
    std::size_t m = l + (r - l) / 2;
    if (pos <= m) {
        int nl = clone_update(pst, pst.pool[static_cast<std::size_t>(cur)].left, l, m, pos, delta);
        pst.pool[static_cast<std::size_t>(cur)].left = nl;
    } else {
        int nr = clone_update(pst, pst.pool[static_cast<std::size_t>(cur)].right, m + 1, r, pos, delta);
        pst.pool[static_cast<std::size_t>(cur)].right = nr;
    }
    int lc = pst.pool[static_cast<std::size_t>(cur)].left;
    int rc = pst.pool[static_cast<std::size_t>(cur)].right;
    pst.pool[static_cast<std::size_t>(cur)].sum = pst.pool[static_cast<std::size_t>(lc)].sum + pst.pool[static_cast<std::size_t>(rc)].sum;
    return cur;
}

std::size_t pst_update(PersistentSegTree& pst, std::size_t version, std::size_t pos, long long delta) {
    int nr = clone_update(pst, pst.roots[version], 0, pst.n - 1, pos, delta);
    pst.roots.push_back(nr);
    return pst.roots.size() - 1;
}

static long long query_rec(const PersistentSegTree& pst, int node, std::size_t l, std::size_t r, std::size_t ql, std::size_t qr) {
    if (ql <= l && r <= qr) return pst.pool[static_cast<std::size_t>(node)].sum;
    std::size_t m = l + (r - l) / 2;
    long long acc = 0;
    if (ql <= m) acc += query_rec(pst, pst.pool[static_cast<std::size_t>(node)].left, l, m, ql, qr);
    if (qr > m) acc += query_rec(pst, pst.pool[static_cast<std::size_t>(node)].right, m + 1, r, ql, qr);
    return acc;
}

long long pst_query_sum(const PersistentSegTree& pst, std::size_t version, std::size_t ql, std::size_t qr) {
    if (pst.n == 0 || ql > qr || version >= pst.roots.size() || qr >= pst.n) return 0;
    return query_rec(pst, pst.roots[version], 0, pst.n - 1, ql, qr);
}

static std::size_t kth_rec(const PersistentSegTree& pst, int nl, int nr, std::size_t l, std::size_t r, long long k) {
    if (l == r) return l;
    std::size_t m = l + (r - l) / 2;
    long long left_cnt = pst.pool[static_cast<std::size_t>(pst.pool[static_cast<std::size_t>(nr)].left)].sum
                       - pst.pool[static_cast<std::size_t>(pst.pool[static_cast<std::size_t>(nl)].left)].sum;
    if (k <= left_cnt) {
        return kth_rec(pst, pst.pool[static_cast<std::size_t>(nl)].left, pst.pool[static_cast<std::size_t>(nr)].left, l, m, k);
    }
    return kth_rec(pst, pst.pool[static_cast<std::size_t>(nl)].right, pst.pool[static_cast<std::size_t>(nr)].right, m + 1, r, k - left_cnt);
}

std::size_t pst_kth_prefix(const PersistentSegTree& pst, std::size_t ver_l, std::size_t ver_r, long long k) {
    return kth_rec(pst, pst.roots[ver_l], pst.roots[ver_r], 0, pst.n - 1, k);
}
} // namespace codes_persistent_seg_tree
