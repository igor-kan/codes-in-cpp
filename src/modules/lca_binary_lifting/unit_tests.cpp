#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_lca_binary_lifting;
    // Tree rooted at 0: 0-1, 0-2, 1-3, 1-4, 4-5, 2-6
    std::vector<std::pair<std::size_t, std::size_t>> edges = {{0,1},{0,2},{1,3},{1,4},{4,5},{2,6}};
    assert(validate_tree_edges(7, edges) == Status::Ok);
    auto idx = build_lca(7, edges, 0);
    assert(query_lca(idx, 3, 5) == 1);
    assert(query_lca(idx, 5, 6) == 0);
    assert(tree_distance(idx, 5, 6) == 5);
    assert(kth_ancestor(idx, 5, 2) == 1);
    assert(verify_lca_properties(idx, 5, 6) == Status::Ok);
    return 0;
}
