#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_eulerian_hierholzer_circuit {
struct DirectedArc {
    int u = 0;
    int v = 0;
};

struct ModuleMeta {
    static constexpr const char* kSlug = "eulerian_hierholzer_circuit";
    int version = 1;
};
} // namespace codes_eulerian_hierholzer_circuit
