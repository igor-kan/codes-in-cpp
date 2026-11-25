#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_kuhn_bipartite_match_d60 {
struct BipartiteEdge {
    int left;
    int right;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "kuhn_bipartite_match_d60";
    int version = 1;
};
} // namespace codes_kuhn_bipartite_match_d60
