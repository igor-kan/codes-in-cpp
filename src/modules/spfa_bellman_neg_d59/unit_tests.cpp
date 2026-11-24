#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_spfa_bellman_neg_d59;
    validate_problem_size(1);
    std::vector<std::vector<SpfaEdge>> g(4);
    g[0] = {{1, 4}, {2, 5}}; g[1] = {{3, -2}}; g[2] = {{1, -3}};
    auto [neg, d] = spfa_distances(4, 0, g);
    assert(!neg && d[1] == 2 && d[3] == 0);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
