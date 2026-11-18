#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_scapegoat_weight_bst;
    validate_problem_size(1);
    ScapegoatTree sg;
    for (int i = 20; i >= 1; --i) sg.insert(i * 10);
    assert(sg.size() == 20 && sg.contains(150) && !sg.contains(155));
    assert(sg.kth(0) == 10 && sg.kth(19) == 200);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
