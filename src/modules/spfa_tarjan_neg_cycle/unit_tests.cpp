#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_spfa_tarjan_neg_cycle;
    validate_problem_size(1);
    auto cyc = find_negative_cycle(4, {{0,1,1},{1,2,-3},{2,3,1},{3,1,1}});
    assert(!cyc.empty() && cyc.front() == cyc.back());
    verify_module_postcondition(true, "unit ok");
    return 0;
}
