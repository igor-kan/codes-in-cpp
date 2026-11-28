#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_bron_kerbosch_clique_d61 {
struct CliqueSummary {
    int count;
    int largest;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "bron_kerbosch_clique_d61";
    int version = 1;
};
} // namespace codes_bron_kerbosch_clique_d61
