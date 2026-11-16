#include "interface.hpp"
#include <cassert>
#include <cstdint>

int main() {
    using namespace codes_rope_chunked_btree;
    uint64_t rng = 0x5152535455565758ULL;
    std::vector<RopeStore> ropes;
    std::vector<std::string> refs;
    for (int k = 0; k < 8; ++k) {
        std::string s = "init_rope_payload_block";
        RopeStore r = rope_from_string(s);
        for (int op = 0; op < 10; ++op) {
            rng = rng * 6364136223846793005ULL + 1ULL;
            std::size_t pos = static_cast<std::size_t>(rng >> 32) % (s.size() + 1);
            std::string ins = (op % 2 == 0) ? "_abc_" : "_XYZ123_";
            rope_insert(r, pos, ins);
            s.insert(pos, ins);
        }
        assert(verify_rope_invariants(r, s) == Status::Ok);
        ropes.push_back(std::move(r));
        refs.push_back(std::move(s));
    }
    auto flats = batch_flatten(ropes);
    for (std::size_t i = 0; i < flats.size(); ++i) assert(flats[i] == refs[i]);
    return 0;
}
