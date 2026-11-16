#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_bimap_bidirectional_index;
    auto bm = make_bimap();
    assert(insert_pair(bm, 1, "alpha") == Status::Ok);
    assert(insert_pair(bm, 2, "beta") == Status::Ok);
    assert(insert_pair(bm, 3, "beta") == Status::InvariantViolation);
    assert(insert_pair(bm, 1, "gamma") == Status::InvariantViolation);
    assert(bimap_size(bm) == 2 && bimap_conflicts(bm) == 2);
    assert(erase_by_key(bm, 1));
    assert(bimap_size(bm) == 1);
    assert(verify_bimap_invariants(bm) == Status::Ok);
    return 0;
}
