#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_merkle_tree_hash_d61;
    validate_problem_size(1);
    MerkleTree mt({"alpha", "beta", "gamma", "delta"});
    assert(mt.leaf_count() == 4);
    assert(mt.root() != 0);
    auto proof = mt.proof(2);
    assert(proof.size() == 2);
    assert(mt.verify(2, "gamma", proof));
    assert(!mt.verify(2, "gammx", proof));
    verify_module_postcondition(true, "unit ok");
    return 0;
}
