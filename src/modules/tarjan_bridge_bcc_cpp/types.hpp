#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_tarjan_bridge_bcc_cpp {
struct EdgeId {
    int u = 0;
    int v = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "tarjan_bridge_bcc_cpp";
    int version = 1;
};
} // namespace codes_tarjan_bridge_bcc_cpp
