#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_scapegoat_weight_bst {

void ScapegoatTree::flatten(int u, std::vector<int>& out) {
    if (u < 0) return;
    flatten(pool_[u].l, out);
    out.push_back(u);
    flatten(pool_[u].r, out);
}

int ScapegoatTree::build_flat(const std::vector<int>& flat, int lo, int hi) {
    if (lo > hi) return -1;
    int mid = (lo + hi) >> 1;
    int u = flat[mid];
    pool_[u].l = build_flat(flat, lo, mid - 1);
    pool_[u].r = build_flat(flat, mid + 1, hi);
    pool_[u].sz = 1 + sz(pool_[u].l) + sz(pool_[u].r);
    return u;
}

int ScapegoatTree::rebuild(int u) {
    std::vector<int> flat;
    flatten(u, flat);
    return build_flat(flat, 0, static_cast<int>(flat.size()) - 1);
}

int ScapegoatTree::insert_rec(int u, std::int64_t key) {
    if (u < 0) {
        int id = static_cast<int>(pool_.size());
        pool_.push_back({key, -1, -1, 1});
        return id;
    }
    if (key < pool_[u].key) pool_[u].l = insert_rec(pool_[u].l, key);
    else if (key > pool_[u].key) pool_[u].r = insert_rec(pool_[u].r, key);
    pool_[u].sz = 1 + sz(pool_[u].l) + sz(pool_[u].r);
    if (sz(pool_[u].l) * 4 > pool_[u].sz * 3 || sz(pool_[u].r) * 4 > pool_[u].sz * 3) {
        return rebuild(u);
    }
    return u;
}

void ScapegoatTree::insert(std::int64_t key) { root_ = insert_rec(root_, key); }

bool ScapegoatTree::contains(std::int64_t key) const {
    int cur = root_;
    while (cur >= 0) {
        if (key == pool_[cur].key) return true;
        cur = (key < pool_[cur].key) ? pool_[cur].l : pool_[cur].r;
    }
    return false;
}

std::int64_t ScapegoatTree::kth(int k) const {
    int cur = root_;
    while (cur >= 0) {
        int lsz = sz(pool_[cur].l);
        if (k == lsz) return pool_[cur].key;
        if (k < lsz) cur = pool_[cur].l;
        else { k -= lsz + 1; cur = pool_[cur].r; }
    }
    return -1;
}

} // namespace codes_scapegoat_weight_bst
