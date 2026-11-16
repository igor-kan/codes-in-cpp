#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_rope_chunked_btree;
    std::string ref = "the_quick_brown_fox_jumps_over";
    RopeStore r = rope_from_string(ref);
    rope_append(r, "_the_lazy_dog");
    ref += "_the_lazy_dog";
    rope_insert(r, 10, "REALLY_");
    ref.insert(10, "REALLY_");
    assert(verify_rope_invariants(r, ref) == Status::Ok);
    return 0;
}
