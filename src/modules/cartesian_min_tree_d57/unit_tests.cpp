#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_cartesian_min_tree_d57;
    validate_problem_size(1);
    std::vector<long long> a = {3, 2, 6, 1, 9};
    auto [root, tree] = build_cartesian_min_tree(a);
    assert(root == 3 && tree[root].left == 1 && tree[root].right == 4);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
