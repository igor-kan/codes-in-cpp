#include "interface.hpp"
#include <cassert>
#include <cstdint>

int main() {
    using namespace codes_small_vector_sso;
    uint64_t s = 0x1122334455667788ULL;
    auto nxt = [&]() -> int64_t { s = s * 6364136223846793005ULL + 1ULL; return static_cast<int64_t>(s >> 32); };
    std::vector<SmallVecInt> batch(12);
    std::vector<std::vector<int64_t>> refs(12);
    for (std::size_t b = 0; b < 12; ++b) {
        std::size_t n = 4 + b * 3;
        for (std::size_t i = 0; i < n; ++i) {
            int64_t x = nxt() % 1000;
            batch[b].push_back(x);
            refs[b].push_back(x);
        }
        assert(verify_small_vec_invariants(batch[b], refs[b]) == Status::Ok);
    }
    auto sums = batch_reduce_sums(batch);
    for (std::size_t b = 0; b < 12; ++b) {
        int64_t rs = 0;
        for (auto x : refs[b]) rs += x;
        assert(sums[b] == rs);
    }
    return 0;
}
