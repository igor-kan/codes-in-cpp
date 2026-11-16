#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_small_vector_sso {
std::vector<int64_t> batch_reduce_sums(const std::vector<SmallVecInt>& batch) {
    std::vector<int64_t> sums(batch.size(), 0);
    if (batch.empty()) return sums;
    std::size_t nt = std::min<std::size_t>(4, batch.size());
    std::vector<std::thread> pool;
    for (std::size_t t = 0; t < nt; ++t) {
        pool.emplace_back([&, t]() {
            for (std::size_t i = t; i < batch.size(); i += nt) {
                int64_t acc = 0;
                for (std::size_t k = 0; k < batch[i].len; ++k) acc += batch[i].ptr[k];
                sums[i] = acc;
            }
        });
    }
    for (auto& th : pool) th.join();
    return sums;
}
} // namespace codes_small_vector_sso
