#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_tarjan_lca_offline_d58;
    validate_problem_size(1);
    auto res = tarjan_offline_lca(5, 0, {{0,1},{0,2},{1,3},{1,4}}, {{3,4},{3,2},{4,0}});
    assert((res == std::vector<int>{1, 0, 0}));
    verify_module_postcondition(true, "unit ok");
    return 0;
}
