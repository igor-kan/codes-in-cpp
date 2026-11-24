#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_lcs_string_reconstruct_d59;
    validate_problem_size(1);
    assert(reconstruct_lcs("AGGTAB", "GXTXAYB") == "GTAB");
    verify_module_postcondition(true, "unit ok");
    return 0;
}
