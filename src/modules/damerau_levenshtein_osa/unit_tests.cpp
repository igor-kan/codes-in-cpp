#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_damerau_levenshtein_osa;
    assert(optimal_string_alignment("ca", "abc") == 3);
    assert(true_damerau_levenshtein("ca", "abc") == 2);
    assert(optimal_string_alignment("abcd", "acbd") == 1);
    assert(true_damerau_levenshtein("abcd", "acbd") == 1);
    assert(verify_dl_invariants("kitten", "sitting", "smitten") == Status::Ok);
    assert(verify_dl_invariants("ca", "ac", "abc") == Status::Ok);
    return 0;
}
