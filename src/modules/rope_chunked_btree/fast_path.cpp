#include "interface.hpp"

namespace codes_rope_chunked_btree {
static void emit_dfs(const RopeStore& r, int id, std::string& dst) {
    if (id < 0) return;
    const auto& nd = r.pool[static_cast<std::size_t>(id)];
    if (nd.left == -1 && nd.right == -1) {
        dst.append(nd.chunk);
        return;
    }
    emit_dfs(r, nd.left, dst);
    emit_dfs(r, nd.right, dst);
}

std::string rope_flatten(const RopeStore& r) {
    if (r.root < 0) return "";
    std::string out;
    out.reserve(r.pool[static_cast<std::size_t>(r.root)].total_len);
    emit_dfs(r, r.root, out);
    return out;
}
} // namespace codes_rope_chunked_btree
