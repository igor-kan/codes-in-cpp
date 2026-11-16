#include "interface.hpp"
#include <stdexcept>

namespace codes_rope_chunked_btree {
static int build_rec(RopeStore& r, const std::string& s, std::size_t l, std::size_t hi) {
    if (hi - l <= 16) {
        int id = static_cast<int>(r.pool.size());
        RopeNode nd;
        nd.chunk = s.substr(l, hi - l);
        nd.total_len = hi - l;
        nd.left_weight = nd.total_len;
        r.pool.push_back(std::move(nd));
        return id;
    }
    std::size_t mid = l + (hi - l) / 2;
    int lc = build_rec(r, s, l, mid);
    int rc = build_rec(r, s, mid, hi);
    int id = static_cast<int>(r.pool.size());
    RopeNode nd;
    nd.left = lc;
    nd.right = rc;
    nd.left_weight = r.pool[static_cast<std::size_t>(lc)].total_len;
    nd.total_len = nd.left_weight + r.pool[static_cast<std::size_t>(rc)].total_len;
    r.pool.push_back(std::move(nd));
    return id;
}

RopeStore rope_from_string(const std::string& s) {
    RopeStore r;
    if (s.empty()) return r;
    r.root = build_rec(r, s, 0, s.size());
    return r;
}

char rope_at(const RopeStore& r, std::size_t idx) {
    if (r.root < 0 || idx >= r.pool[static_cast<std::size_t>(r.root)].total_len) {
        throw std::out_of_range("rope index out of range");
    }
    int cur = r.root;
    while (true) {
        const auto& nd = r.pool[static_cast<std::size_t>(cur)];
        if (nd.left == -1 && nd.right == -1) return nd.chunk[idx];
        if (idx < nd.left_weight) cur = nd.left;
        else { idx -= nd.left_weight; cur = nd.right; }
    }
}

void rope_append(RopeStore& r, const std::string& suffix) {
    if (suffix.empty()) return;
    int rc = build_rec(r, suffix, 0, suffix.size());
    if (r.root < 0) { r.root = rc; return; }
    int nr = static_cast<int>(r.pool.size());
    RopeNode nd;
    nd.left = r.root;
    nd.right = rc;
    nd.left_weight = r.pool[static_cast<std::size_t>(r.root)].total_len;
    nd.total_len = nd.left_weight + r.pool[static_cast<std::size_t>(rc)].total_len;
    r.pool.push_back(std::move(nd));
    r.root = nr;
}

static int split_copy(RopeStore& r, int id, std::size_t k, bool take_left) {
    if (id < 0 || k == 0) return take_left ? -1 : id;
    const RopeNode nd = r.pool[static_cast<std::size_t>(id)];
    if (k >= nd.total_len) return take_left ? id : -1;
    if (nd.left == -1 && nd.right == -1) {
        std::string sub = take_left ? nd.chunk.substr(0, k) : nd.chunk.substr(k);
        return build_rec(r, sub, 0, sub.size());
    }
    if (k <= nd.left_weight) {
        int lc = split_copy(r, nd.left, k, take_left);
        if (take_left) return lc;
        if (lc < 0) return nd.right;
        int nid = static_cast<int>(r.pool.size());
        RopeNode comb{r.pool[static_cast<std::size_t>(lc)].total_len + r.pool[static_cast<std::size_t>(nd.right)].total_len,
                      r.pool[static_cast<std::size_t>(lc)].total_len, "", lc, nd.right};
        r.pool.push_back(comb);
        return nid;
    } else {
        int rc = split_copy(r, nd.right, k - nd.left_weight, take_left);
        if (!take_left) return rc;
        if (rc < 0) return nd.left;
        int nid = static_cast<int>(r.pool.size());
        RopeNode comb{r.pool[static_cast<std::size_t>(nd.left)].total_len + r.pool[static_cast<std::size_t>(rc)].total_len,
                      r.pool[static_cast<std::size_t>(nd.left)].total_len, "", nd.left, rc};
        r.pool.push_back(comb);
        return nid;
    }
}

void rope_insert(RopeStore& r, std::size_t pos, const std::string& ins) {
    if (ins.empty()) return;
    if (r.root < 0) { r = rope_from_string(ins); return; }
    std::size_t n = r.pool[static_cast<std::size_t>(r.root)].total_len;
    if (pos > n) throw std::out_of_range("insert pos out of bounds");
    if (pos == n) { rope_append(r, ins); return; }
    int left_part = split_copy(r, r.root, pos, true);
    int right_part = split_copy(r, r.root, pos, false);
    int mid_part = build_rec(r, ins, 0, ins.size());
    int lr = left_part;
    if (lr < 0) lr = mid_part;
    else {
        int nid = static_cast<int>(r.pool.size());
        RopeNode comb{r.pool[static_cast<std::size_t>(lr)].total_len + r.pool[static_cast<std::size_t>(mid_part)].total_len,
                      r.pool[static_cast<std::size_t>(lr)].total_len, "", lr, mid_part};
        r.pool.push_back(comb);
        lr = nid;
    }
    if (right_part < 0) { r.root = lr; return; }
    int nr = static_cast<int>(r.pool.size());
    RopeNode comb{r.pool[static_cast<std::size_t>(lr)].total_len + r.pool[static_cast<std::size_t>(right_part)].total_len,
                  r.pool[static_cast<std::size_t>(lr)].total_len, "", lr, right_part};
    r.pool.push_back(comb);
    r.root = nr;
}
} // namespace codes_rope_chunked_btree
