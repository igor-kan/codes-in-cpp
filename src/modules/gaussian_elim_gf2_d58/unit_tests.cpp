#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_gaussian_elim_gf2_d58;
    validate_problem_size(1);
    assert(gf2_max_subset_xor({1, 2, 4, 8}) == 15);
    assert(gf2_max_subset_xor({9, 8, 5}) == 13);
    assert(gf2_basis_rank({3, 5, 6}) == 2);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
