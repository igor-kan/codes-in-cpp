#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_treap_implicit_rev_d58;
    validate_problem_size(1);
    std::vector<long long> a = {1, 2, 3, 4, 5};
    reverse_subarray_twice_check(a, 1, 3);
    assert((a == std::vector<long long>{1, 4, 3, 2, 5}));
    reverse_subarray_twice_check(a, 1, 3);
    assert((a == std::vector<long long>{1, 2, 3, 4, 5}));
    verify_module_postcondition(true, "unit ok");
    return 0;
}
