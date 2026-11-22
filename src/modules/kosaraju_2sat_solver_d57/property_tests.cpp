#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_kosaraju_2sat_solver_d57;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<SatClause> unsat = {{0,false,0,false},{0,true,0,true}};
    assert(!solve_two_sat(1, unsat).first);
    return 0;
}
