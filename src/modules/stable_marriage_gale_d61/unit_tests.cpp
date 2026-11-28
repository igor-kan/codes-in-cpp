#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_stable_marriage_gale_d61;
    validate_problem_size(1);
    StableMarriage sm(3);
    sm.set_proposer_preferences(0, {0, 1, 2});
    sm.set_proposer_preferences(1, {0, 1, 2});
    sm.set_proposer_preferences(2, {1, 0, 2});
    sm.set_receiver_preferences(0, {1, 0, 2});
    sm.set_receiver_preferences(1, {2, 0, 1});
    sm.set_receiver_preferences(2, {0, 1, 2});
    auto match = sm.solve();
    assert((match == std::vector<int>{2, 0, 1}));
    assert(sm.is_stable(match));
    auto matched = sm.pairs(match);
    assert(matched.size() == 3 && sm.size() == 3);
    StableMarriage empty(0);
    assert(empty.solve().empty() && empty.size() == 0);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
