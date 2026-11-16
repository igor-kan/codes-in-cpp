#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_small_vector_sso;
    SmallVecInt v;
    std::vector<int64_t> ref;
    for (int64_t i = 0; i < 16; ++i) {
        v.push_back(i * 3);
        ref.push_back(i * 3);
    }
    assert(v.is_small());
    assert(verify_small_vec_invariants(v, ref) == Status::Ok);
    v.push_back(99);
    ref.push_back(99);
    assert(!v.is_small());
    SmallVecInt cp = v;
    SmallVecInt mv = std::move(v);
    assert(v.len == 0 && v.is_small());
    assert(verify_small_vec_invariants(cp, ref) == Status::Ok);
    assert(verify_small_vec_invariants(mv, ref) == Status::Ok);
    return 0;
}
