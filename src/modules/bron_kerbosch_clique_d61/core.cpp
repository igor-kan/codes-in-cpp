#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_bron_kerbosch_clique_d61 {

BronKerbosch::BronKerbosch(int vertices) : n_(vertices > 0 ? vertices : 0) {
    adj_.assign(static_cast<std::size_t>(n_), std::vector<char>(static_cast<std::size_t>(n_), 0));
}
int BronKerbosch::vertex_count() const {
    return n_;
}
void BronKerbosch::add_edge(int u, int v) {
    if (u < 0 || u >= n_ || v < 0 || v >= n_ || u == v) return;
    adj_[static_cast<std::size_t>(u)][static_cast<std::size_t>(v)] = 1;
    adj_[static_cast<std::size_t>(v)][static_cast<std::size_t>(u)] = 1;
}
bool BronKerbosch::adjacent(int u, int v) const {
    if (u < 0 || u >= n_ || v < 0 || v >= n_) return false;
    return adj_[static_cast<std::size_t>(u)][static_cast<std::size_t>(v)] != 0;
}
void BronKerbosch::expand(std::vector<int> r, std::vector<int> p, std::vector<int> x,
                          std::vector<std::vector<int>>& out) const {
    if (p.empty() && x.empty()) {
        out.push_back(r);
        return;
    }
    int pivot = -1;
    int best = -1;
    auto score = [this, &p](int u) {
        int count = 0;
        for (int w : p) {
            if (adjacent(u, w)) ++count;
        }
        return count;
    };
    for (int u : p) {
        int count = score(u);
        if (count > best) {
            best = count;
            pivot = u;
        }
    }
    for (int u : x) {
        int count = score(u);
        if (count > best) {
            best = count;
            pivot = u;
        }
    }
    std::vector<int> candidates;
    for (int v : p) {
        if (pivot < 0 || !adjacent(pivot, v)) candidates.push_back(v);
    }
    for (int v : candidates) {
        std::vector<int> next_r = r;
        next_r.push_back(v);
        std::vector<int> next_p;
        std::vector<int> next_x;
        for (int w : p) {
            if (adjacent(v, w)) next_p.push_back(w);
        }
        for (int w : x) {
            if (adjacent(v, w)) next_x.push_back(w);
        }
        expand(next_r, next_p, next_x, out);
        p.erase(std::remove(p.begin(), p.end(), v), p.end());
        x.push_back(v);
    }
}
std::vector<std::vector<int>> BronKerbosch::maximal_cliques() const {
    std::vector<std::vector<int>> out;
    if (n_ <= 0) return out;
    std::vector<int> r;
    std::vector<int> p;
    std::vector<int> x;
    for (int v = 0; v < n_; ++v) p.push_back(v);
    expand(r, p, x, out);
    return out;
}
CliqueSummary BronKerbosch::summary() const {
    std::vector<std::vector<int>> cliques = maximal_cliques();
    int largest = 0;
    for (const std::vector<int>& clique : cliques) {
        int size = static_cast<int>(clique.size());
        if (size > largest) largest = size;
    }
    return CliqueSummary{static_cast<int>(cliques.size()), largest};
}

} // namespace codes_bron_kerbosch_clique_d61
