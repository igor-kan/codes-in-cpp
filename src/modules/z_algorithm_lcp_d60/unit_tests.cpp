#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_z_algorithm_lcp_d60;
    validate_problem_size(1);
    auto hits = z_find_all("ababcababa", "aba");
    assert((hits == std::vector<int>{0, 5, 7}));
    verify_module_postcondition(true, "unit ok");
    return 0;
}
