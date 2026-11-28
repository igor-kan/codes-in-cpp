#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_merkle_tree_hash_d61;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    MerkleTree mt({"a", "b", "c", "d", "e"});
    assert(mt.leaf_count() == 5);
    for (std::size_t i = 0; i < mt.leaf_count(); ++i) {
        auto proof = mt.proof(i);
        assert(mt.verify(i, std::string(1, static_cast<char>('a' + i)), proof));
    }
    auto first = mt.proof(0);
    assert(!mt.verify(0, "z", first));
    assert(mt.root() == mt.root());
    return 0;
}
