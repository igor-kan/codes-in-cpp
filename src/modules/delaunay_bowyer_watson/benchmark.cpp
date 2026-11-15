#include "interface.hpp"
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    std::size_t sink = 0;
    std::vector<codes_delaunay_bowyer_watson::Pt2> pts; for(int i=0;i<30;++i){double r=1.0+0.3*i,a=i*2.39996; pts.push_back({r*std::cos(a),r*std::sin(a)});}
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        sink += codes_delaunay_bowyer_watson::bowyer_watson_triangulate(pts).size();
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "delaunay_bowyer_watson ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
