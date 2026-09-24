#include "heston_stochastic_vol_step.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(heston_var_trunc(-0.01) == 0.0); assert(heston_var_trunc(0.04) == 0.04);
    std::cout << "test_heston_stochastic_vol_step.cpp passed.\n";
    return 0;
}
