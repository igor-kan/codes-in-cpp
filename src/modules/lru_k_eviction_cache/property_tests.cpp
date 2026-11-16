#include "interface.hpp"
#include <cassert>
#include <cstdint>

int main() {
    using namespace codes_lru_k_eviction_cache;
    uint64_t rng = 0x4242424242424242ULL;
    std::vector<std::vector<int64_t>> traces(8);
    for (auto& tr : traces) {
        for (int i = 0; i < 200; ++i) {
            rng = rng * 6364136223846793005ULL + 1ULL;
            tr.push_back((i % 5 == 0) ? 1 : static_cast<int64_t>((rng >> 32) % 30));
        }
    }
    auto res = batch_simulate_lru2(8, traces);
    for (auto hits : res) assert(hits > 0);
    return 0;
}
