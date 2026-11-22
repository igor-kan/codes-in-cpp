#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_kosaraju_2sat_solver_d57;
    validate_problem_size(1);
    std::vector<SatClause> cls = {{0,false,1,false},{0,true,1,false},{1,true,0,true}};
    auto [ok, asn] = solve_two_sat(2, cls);
    assert(ok && asn[1] == true && asn[0] == false);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
