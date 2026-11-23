#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_tarjan_lca_offline_d58 {
struct LcaQuerySpec {
    int u = 0;
    int v = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "tarjan_lca_offline_d58";
    int version = 1;
};
} // namespace codes_tarjan_lca_offline_d58
