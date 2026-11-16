#include "interface.hpp"
#include <algorithm>
#include <cassert>
#include <cstdint>

int main() {
    using namespace codes_interval_scheduling_weighted;
    uint64_t s = 0xDEADBEEF00112233ULL;
    auto nxt = [&]() -> int64_t { s = s * 6364136223846793005ULL + 1ULL; return static_cast<int64_t>((s >> 32) % 30); };
    std::vector<std::vector<WeightedJob>> suites;
    for (int k = 0; k < 14; ++k) {
        std::vector<WeightedJob> js;
        for (std::size_t id = 0; id < 12; ++id) {
            int64_t a = nxt();
            int64_t len = 1 + (nxt() % 8);
            js.push_back({a, a + len, 1 + (nxt() % 25), id});
        }
        suites.push_back(std::move(js));
    }
    auto plans = batch_schedule_plans(suites);
    for (std::size_t i = 0; i < suites.size(); ++i) {
        assert(plans[i].max_weight == max_weight_dp_fast(suites[i]));
        assert(verify_schedule_invariants(suites[i], plans[i]) == Status::Ok);
        // 2^12 exhaustive check
        int64_t best = 0;
        for (uint32_t mask = 0; mask < (1U << 12); ++mask) {
            std::vector<WeightedJob> sub;
            int64_t w = 0;
            for (std::size_t b = 0; b < 12; ++b) {
                if (mask & (1U << b)) { sub.push_back(suites[i][b]); w += suites[i][b].weight; }
            }
            std::sort(sub.begin(), sub.end(), [](const WeightedJob& x, const WeightedJob& y) { return x.start < y.start; });
            bool ok = true;
            for (std::size_t b = 1; b < sub.size(); ++b) if (sub[b-1].finish > sub[b].start) { ok = false; break; }
            if (ok && w > best) best = w;
        }
        assert(best == plans[i].max_weight);
    }
    return 0;
}
