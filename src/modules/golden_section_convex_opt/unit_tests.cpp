#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_golden_section_convex_opt;
    validate_problem_size(1);
    auto fn = +[](double x) { return (x - 3.25) * (x - 3.25) + 1.5; };
    auto res = golden_section_minimize(fn, -5.0, 10.0, 1e-9);
    assert(std::fabs(res.x - 3.25) < 1e-7 && std::fabs(res.fx - 1.5) < 1e-12);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
