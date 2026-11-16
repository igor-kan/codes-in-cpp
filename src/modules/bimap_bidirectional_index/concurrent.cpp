#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_bimap_bidirectional_index {
std::vector<bool> batch_verify_keys(const IntStrBiMap& bm, const std::vector<int64_t>& keys) {
    std::vector<bool> out(keys.size(), false);
    if (keys.empty()) return out;
    std::size_t nt = std::min<std::size_t>(4, keys.size());
    std::vector<std::thread> pool;
    for (std::size_t t = 0; t < nt; ++t) {
        pool.emplace_back([&, t]() {
            std::string tmp;
            for (std::size_t i = t; i < keys.size(); i += nt) {
                if (find_by_key(bm, keys[i], tmp)) {
                    int64_t back = -1;
                    out[i] = find_by_val(bm, tmp, back) && (back == keys[i]);
                }
            }
        });
    }
    for (auto& th : pool) th.join();
    return out;
}
} // namespace codes_bimap_bidirectional_index
