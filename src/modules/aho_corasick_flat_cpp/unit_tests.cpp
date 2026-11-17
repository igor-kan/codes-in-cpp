#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_aho_corasick_flat_cpp;
    FlatAhoCorasick ac({"he", "she", "his", "hers"});
    assert(ac.state_count() == 10);
    int c = ac.count_matches("ahishers");
    verify_ac_parity({"he", "she", "his", "hers"}, "ahishers", c);
    return 0;
}
