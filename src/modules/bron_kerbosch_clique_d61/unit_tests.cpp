#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_bron_kerbosch_clique_d61;
    validate_problem_size(1);
    BronKerbosch triangle(4);
    triangle.add_edge(0, 1);
    triangle.add_edge(1, 2);
    triangle.add_edge(0, 2);
    assert(triangle.adjacent(0, 2));
    assert(!triangle.adjacent(0, 3));
    auto cliques = triangle.maximal_cliques();
    assert(cliques.size() == 2);
    bool saw_triangle = false;
    bool saw_isolated = false;
    for (const auto& clique : cliques) {
        if (clique.size() == 3) saw_triangle = true;
        if (clique.size() == 1 && clique[0] == 3) saw_isolated = true;
    }
    assert(saw_triangle && saw_isolated);
    auto tri_summary = triangle.summary();
    assert(tri_summary.count == 2 && tri_summary.largest == 3);
    BronKerbosch path(3);
    path.add_edge(0, 1);
    path.add_edge(1, 2);
    assert(path.maximal_cliques().size() == 2);
    assert(path.summary().largest == 2);
    BronKerbosch complete(4);
    for (int u = 0; u < 4; ++u) {
        for (int v = u + 1; v < 4; ++v) complete.add_edge(u, v);
    }
    auto complete_summary = complete.summary();
    assert(complete_summary.count == 1 && complete_summary.largest == 4);
    assert(complete.vertex_count() == 4);
    BronKerbosch empty(0);
    assert(empty.maximal_cliques().empty());
    assert(empty.summary().count == 0 && empty.summary().largest == 0);
    verify_module_postcondition(true, "unit ok");
    return 0;
}
