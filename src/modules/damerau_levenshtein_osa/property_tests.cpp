#include "interface.hpp"
#include <cassert>
#include <cstdint>

int main() {
    using namespace codes_damerau_levenshtein_osa;
    uint64_t rng = 0x33445566778899AAULL;
    auto mk = [&]() {
        std::string s(10, 'a');
        for (char& ch : s) {
            rng = rng * 6364136223846793005ULL + 1ULL;
            ch = static_cast<char>('a' + ((rng >> 32) % 4));
        }
        return s;
    };
    std::vector<std::pair<std::string, std::string>> pairs;
    for (int k = 0; k < 16; ++k) {
        std::string a = mk(), b = mk(), c = mk();
        assert(verify_dl_invariants(a, b, c) == Status::Ok);
        pairs.push_back({a, b});
    }
    auto res = batch_edit_distances(pairs);
    for (const auto& m : res) assert(m.osa_distance >= m.true_dl_distance);
    return 0;
}
