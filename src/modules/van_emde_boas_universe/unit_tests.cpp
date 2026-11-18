#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_van_emde_boas_universe;
    validate_problem_size(1);
    FlatVebSet veb(1024);
    veb.insert(5); veb.insert(130); veb.insert(900);
    assert(veb.successor(5) == 130 && veb.successor(130) == 900);
    assert(veb.predecessor(900) == 130);
    veb.erase(130);
    assert(veb.successor(5) == 900);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
