#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_lca_binary_lifting;
    std::size_t n = 63; // complete binary tree of height 5
    std::vector<std::pair<std::size_t, std::size_t>> edges;
    for (std::size_t i = 1; i < n; ++i) edges.push_back({(i - 1) / 2, i});
    auto idx = build_lca(n, edges, 0);
    for (std::size_t u = 0; u < n; ++u) {
        for (std::size_t v = u; v < n; v += 5) {
            assert(query_lca(idx, u, v) == query_lca(idx, v, u));
            assert(verify_lca_properties(idx, u, v) == Status::Ok);
            std::size_t l = query_lca(idx, u, v);
            assert(kth_ancestor(idx, u, idx.depth[u] - idx.depth[l]) == l);
        }
    }
    return 0;
}
