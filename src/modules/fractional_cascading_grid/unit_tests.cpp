#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_fractional_cascading_grid;
    validate_problem_size(1);
    FractionalCascader fc({{10, 20, 30, 40}, {5, 15, 25, 35}, {12, 24, 36}});
    auto res = fc.query_lower_bounds(22);
    assert((res == std::vector<std::int64_t>{30, 25, 24}));
    verify_module_postcondition(true, "unit ok");
    return 0;
}
