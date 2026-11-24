#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_scc_condensation_d59;
    validate_problem_size(1);
    auto res = tarjan_scc_condense(4, {{0,1},{1,0},{1,2},{2,3},{3,2}});
    assert(res.comp_count == 2 && res.comp_id[0] == res.comp_id[1] && res.comp_id[2] == res.comp_id[3]);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
