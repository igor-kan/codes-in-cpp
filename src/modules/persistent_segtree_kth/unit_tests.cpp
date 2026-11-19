#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_persistent_segtree_kth;
    validate_problem_size(1);
    PersistentFreqTree pst(16);
    std::vector<int> vals = {5, 1, 9, 3, 7, 2};
    std::vector<int> roots(vals.size() + 1, 0);
    for (std::size_t i = 0; i < vals.size(); ++i) roots[i + 1] = pst.add(roots[i], 0, 15, vals[i]);
    assert(pst.kth(roots[1], roots[5], 0, 15, 2) == 3);
    assert(pst.kth(roots[0], roots[6], 0, 15, 4) == 5);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
