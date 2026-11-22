#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_suffix_array_doubling_d57;
    validate_problem_size(1);
    std::string s = "banana";
    auto sa = build_suffix_array(s);
    assert((sa == std::vector<int>{5, 3, 1, 0, 4, 2}));
    assert(sa_contains(s, sa, "nan") && !sa_contains(s, sa, "apple"));
    verify_module_postcondition(true, "unit ok");
    return 0;
}
