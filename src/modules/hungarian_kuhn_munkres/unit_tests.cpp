#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_hungarian_kuhn_munkres;
    std::vector<long long> mat = {
        8, 4, 7,
        5, 2, 3,
        9, 4, 8
    };
    // Optimal: row0->col1 (4), row1->col2 (3), row2->col0 (9)? Wait:
    // perm(0->2:7, 1->0:5, 2->1:4) = 16; perm(0->1:4, 1->2:3, 2->0:9) = 16; perm(0->0:8, 1->2:3, 2->1:4) = 15!
    assert(validate_cost_matrix(3, 3, mat) == Status::Ok);
    auto r = solve_hungarian(3, 3, mat);
    assert(r.min_cost == 15);
    assert(verify_assignment_bijection(3, 3, mat, r) == Status::Ok);
    return 0;
}
