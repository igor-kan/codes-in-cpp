#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_kruskal_dsu_mst_weight;
    validate_problem_size(1);
    auto [w, cnt] = kruskal_mst(4, {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}});
    assert(w == 19 && cnt == 3);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
