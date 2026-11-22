#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_kosaraju_2sat_solver_d57 {

std::pair<bool, std::vector<bool>> solve_two_sat(int vars, const std::vector<SatClause>& clauses) {
    if (vars <= 0) throw std::invalid_argument("positive vars");
    int N = 2 * vars;
    std::vector<std::vector<int>> g(N), rg(N);
    auto add_imp = [&](int u, int v) {
        g[u].push_back(v);
        rg[v].push_back(u);
    };
    for (const auto& c : clauses) {
        int ua = 2 * c.a + (c.neg_a ? 1 : 0);
        int vb = 2 * c.b + (c.neg_b ? 1 : 0);
        add_imp(ua ^ 1, vb);
        add_imp(vb ^ 1, ua);
    }
    std::vector<bool> vis(N, false);
    std::vector<int> order;
    auto dfs1 = [&](auto& self, int u) -> void {
        vis[u] = true;
        for (int v : g[u]) if (!vis[v]) self(self, v);
        order.push_back(u);
    };
    for (int i = 0; i < N; ++i) if (!vis[i]) dfs1(dfs1, i);
    std::vector<int> comp(N, -1);
    int cid = 0;
    auto dfs2 = [&](auto& self, int u) -> void {
        comp[u] = cid;
        for (int v : rg[u]) if (comp[v] == -1) self(self, v);
    };
    for (int i = N - 1; i >= 0; --i) {
        int u = order[i];
        if (comp[u] == -1) { dfs2(dfs2, u); ++cid; }
    }
    std::vector<bool> val(vars, false);
    for (int i = 0; i < vars; ++i) {
        if (comp[2 * i] == comp[2 * i + 1]) return {false, {}};
        val[i] = comp[2 * i] > comp[2 * i + 1];
    }
    return {true, val};
}

} // namespace codes_kosaraju_2sat_solver_d57
