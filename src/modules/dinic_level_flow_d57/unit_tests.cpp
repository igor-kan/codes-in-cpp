#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_dinic_level_flow_d57;
    validate_problem_size(1);
    DinicSolver dn(4);
    dn.add_edge(0, 1, 10); dn.add_edge(0, 2, 10);
    dn.add_edge(1, 2, 2); dn.add_edge(1, 3, 4);
    dn.add_edge(2, 3, 14);
    assert(dn.max_flow(0, 3) == 16);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
