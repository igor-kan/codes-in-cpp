#include "interface.hpp"
#include <algorithm>
#include <thread>

namespace codes_rope_chunked_btree {
std::vector<std::string> batch_flatten(const std::vector<RopeStore>& ropes) {
    std::vector<std::string> out(ropes.size());
    if (ropes.empty()) return out;
    std::size_t nt = std::min<std::size_t>(4, ropes.size());
    std::vector<std::thread> pool;
    for (std::size_t t = 0; t < nt; ++t) {
        pool.emplace_back([&, t]() {
            for (std::size_t i = t; i < ropes.size(); i += nt) {
                out[i] = rope_flatten(ropes[i]);
            }
        });
    }
    for (auto& th : pool) th.join();
    return out;
}
} // namespace codes_rope_chunked_btree
