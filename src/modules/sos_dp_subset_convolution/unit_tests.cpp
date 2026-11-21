#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_sos_dp_subset_convolution;
    validate_problem_size(1);
    std::vector<long long> f = {1, 2, 4, 8};
    auto z = sos_zeta(f, 2);
    assert((z == std::vector<long long>{1, 3, 5, 15}));
    assert(sos_mobius(z, 2) == f);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
