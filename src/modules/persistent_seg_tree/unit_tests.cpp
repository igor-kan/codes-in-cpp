#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_persistent_seg_tree;
    auto pst = pst_create({0, 0, 0, 0, 0});
    auto v1 = pst_update(pst, 0, 2, 1); // [0,0,1,0,0]
    auto v2 = pst_update(pst, v1, 0, 1); // [1,0,1,0,0]
    auto v3 = pst_update(pst, v2, 4, 2); // [1,0,1,0,2]
    assert(pst_query_sum(pst, 0, 0, 4) == 0);
    assert(pst_query_sum(pst, v1, 0, 4) == 1);
    assert(pst_query_sum(pst, v2, 0, 2) == 2);
    assert(pst_query_sum(pst, v3, 1, 4) == 3);
    assert(pst_kth_prefix(pst, v1, v3, 1) == 0);
    assert(pst_kth_prefix(pst, v1, v3, 2) == 4);
    assert(verify_pst_node_sums(pst, pst.roots[v3], 0, 4) == Status::Ok);
    assert(validate_version_query(pst, 99, 0, 1) == Status::OutOfBounds);
    return 0;
}
