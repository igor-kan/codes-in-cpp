#include "interface.hpp"
#include <cassert>
#include <string>

int main() {
    using namespace codes_bimap_bidirectional_index;
    auto bm = make_bimap();
    std::vector<int64_t> keys;
    for (int64_t k = 1; k <= 100; ++k) {
        assert(insert_pair(bm, k, "node_" + std::to_string(k)) == Status::Ok);
        keys.push_back(k);
    }
    auto res = batch_verify_keys(bm, keys);
    for (bool ok : res) assert(ok);
    for (int64_t k = 1; k <= 50; k += 2) assert(erase_by_key(bm, k));
    assert(verify_bimap_invariants(bm) == Status::Ok);
    return 0;
}
