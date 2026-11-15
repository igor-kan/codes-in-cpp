#include "interface.hpp"
#include <algorithm>
#include <limits>

namespace codes_splay_tree_amortized {
static int dir_of(const SplayTree& t, int x) {
    int p = t.pool[static_cast<std::size_t>(x)].parent;
    return (t.pool[static_cast<std::size_t>(p)].ch[1] == x) ? 1 : 0;
}

void splay_pull(SplayTree& tree, int x) {
    if (x < 0) return;
    SplayNode& n = tree.pool[static_cast<std::size_t>(x)];
    std::size_t ls = (n.ch[0] >= 0) ? tree.pool[static_cast<std::size_t>(n.ch[0])].sz : 0;
    std::size_t rs = (n.ch[1] >= 0) ? tree.pool[static_cast<std::size_t>(n.ch[1])].sz : 0;
    n.sz = 1 + ls + rs;
}

void splay_rotate(SplayTree& tree, int x) {
    int p = tree.pool[static_cast<std::size_t>(x)].parent;
    int g = tree.pool[static_cast<std::size_t>(p)].parent;
    int d = dir_of(tree, x);
    int b = tree.pool[static_cast<std::size_t>(x)].ch[d ^ 1];
    if (g >= 0) tree.pool[static_cast<std::size_t>(g)].ch[dir_of(tree, p)] = x;
    tree.pool[static_cast<std::size_t>(x)].parent = g;
    tree.pool[static_cast<std::size_t>(x)].ch[d ^ 1] = p;
    tree.pool[static_cast<std::size_t>(p)].parent = x;
    tree.pool[static_cast<std::size_t>(p)].ch[d] = b;
    if (b >= 0) tree.pool[static_cast<std::size_t>(b)].parent = p;
    splay_pull(tree, p);
    splay_pull(tree, x);
}

void splay(SplayTree& tree, int x) {
    if (x < 0) return;
    while (tree.pool[static_cast<std::size_t>(x)].parent >= 0) {
        int p = tree.pool[static_cast<std::size_t>(x)].parent;
        int g = tree.pool[static_cast<std::size_t>(p)].parent;
        if (g >= 0) {
            if (dir_of(tree, x) == dir_of(tree, p)) splay_rotate(tree, p);
            else splay_rotate(tree, x);
        }
        splay_rotate(tree, x);
    }
    tree.root = x;
}

bool splay_insert(SplayTree& tree, long long key) {
    int cur = tree.root, par = -1, d = 0;
    while (cur >= 0) {
        long long ck = tree.pool[static_cast<std::size_t>(cur)].key;
        if (ck == key) { splay(tree, cur); return false; }
        par = cur;
        d = (key > ck) ? 1 : 0;
        cur = tree.pool[static_cast<std::size_t>(cur)].ch[d];
    }
    int nid = static_cast<int>(tree.pool.size());
    SplayNode node;
    node.key = key;
    node.parent = par;
    tree.pool.push_back(node);
    if (par >= 0) tree.pool[static_cast<std::size_t>(par)].ch[d] = nid;
    splay(tree, nid);
    return true;
}

bool splay_contains(SplayTree& tree, long long key) {
    int cur = tree.root, last = -1;
    while (cur >= 0) {
        last = cur;
        long long ck = tree.pool[static_cast<std::size_t>(cur)].key;
        if (ck == key) { splay(tree, cur); return true; }
        cur = tree.pool[static_cast<std::size_t>(cur)].ch[(key > ck) ? 1 : 0];
    }
    if (last >= 0) splay(tree, last);
    return false;
}

bool splay_erase(SplayTree& tree, long long key) {
    if (!splay_contains(tree, key)) return false;
    int r = tree.root;
    int lc = tree.pool[static_cast<std::size_t>(r)].ch[0];
    int rc = tree.pool[static_cast<std::size_t>(r)].ch[1];
    if (lc >= 0) tree.pool[static_cast<std::size_t>(lc)].parent = -1;
    if (rc >= 0) tree.pool[static_cast<std::size_t>(rc)].parent = -1;
    if (lc < 0) { tree.root = rc; return true; }
    int mx = lc;
    while (tree.pool[static_cast<std::size_t>(mx)].ch[1] >= 0) {
        mx = tree.pool[static_cast<std::size_t>(mx)].ch[1];
    }
    tree.root = lc;
    splay(tree, mx);
    tree.pool[static_cast<std::size_t>(mx)].ch[1] = rc;
    if (rc >= 0) tree.pool[static_cast<std::size_t>(rc)].parent = mx;
    splay_pull(tree, mx);
    return true;
}

bool kth_element(SplayTree& tree, std::size_t k, long long& out_key) {
    int cur = tree.root;
    while (cur >= 0) {
        int lc = tree.pool[static_cast<std::size_t>(cur)].ch[0];
        std::size_t ls = (lc >= 0) ? tree.pool[static_cast<std::size_t>(lc)].sz : 0;
        if (k < ls) cur = lc;
        else if (k == ls) { out_key = tree.pool[static_cast<std::size_t>(cur)].key; splay(tree, cur); return true; }
        else { k -= ls + 1; cur = tree.pool[static_cast<std::size_t>(cur)].ch[1]; }
    }
    return false;
}
} // namespace codes_splay_tree_amortized
