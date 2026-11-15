#include "interface.hpp"
#include <stack>

namespace codes_lca_binary_lifting {
LcaIndex build_lca(std::size_t n, const std::vector<std::pair<std::size_t, std::size_t>>& edges, std::size_t root) {
    LcaIndex idx;
    idx.n = n;
    idx.root = root;
    idx.log_n = 1;
    while ((1ULL << idx.log_n) <= n) ++idx.log_n;
    idx.depth.assign(n, 0);
    idx.tin.assign(n, 0);
    idx.tout.assign(n, 0);
    idx.up.assign(idx.log_n * n, root);

    std::vector<std::vector<std::size_t>> adj(n);
    for (const auto& e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    struct Frame { std::size_t u, p, child_idx; bool entered; };
    std::vector<Frame> st;
    st.push_back({root, root, 0, false});
    std::size_t timer = 0;
    while (!st.empty()) {
        auto& f = st.back();
        if (!f.entered) {
            f.entered = true;
            idx.tin[f.u] = ++timer;
            idx.up[f.u] = f.p;
            for (std::size_t k = 1; k < idx.log_n; ++k) {
                std::size_t mid = idx.up[(k - 1) * n + f.u];
                idx.up[k * n + f.u] = idx.up[(k - 1) * n + mid];
            }
        }
        if (f.child_idx < adj[f.u].size()) {
            std::size_t v = adj[f.u][f.child_idx++];
            if (v != f.p) {
                idx.depth[v] = idx.depth[f.u] + 1;
                st.push_back({v, f.u, 0, false});
            }
        } else {
            idx.tout[f.u] = ++timer;
            st.pop_back();
        }
    }
    return idx;
}

bool is_ancestor(const LcaIndex& idx, std::size_t u, std::size_t v) {
    return idx.tin[u] <= idx.tin[v] && idx.tout[v] <= idx.tout[u];
}

std::size_t query_lca(const LcaIndex& idx, std::size_t u, std::size_t v) {
    if (is_ancestor(idx, u, v)) return u;
    if (is_ancestor(idx, v, u)) return v;
    for (std::size_t k = idx.log_n; k-- > 0;) {
        std::size_t anc = idx.up[k * idx.n + u];
        if (!is_ancestor(idx, anc, v)) u = anc;
    }
    return idx.up[u];
}

std::size_t tree_distance(const LcaIndex& idx, std::size_t u, std::size_t v) {
    std::size_t l = query_lca(idx, u, v);
    return idx.depth[u] + idx.depth[v] - 2 * idx.depth[l];
}
} // namespace codes_lca_binary_lifting
