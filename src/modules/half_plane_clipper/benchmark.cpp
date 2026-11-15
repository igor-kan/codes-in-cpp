#include "interface.hpp"
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>

int main() {
    std::size_t sink = 0;
    std::vector<codes_half_plane_clipper::HalfPlane> hps; for(int k=0;k<32;++k){double a=2.0*3.14159265358979*k/32.0; hps.push_back({{std::cos(a),std::sin(a)},{-std::sin(a),std::cos(a)}});}
    auto t0 = std::chrono::steady_clock::now();
    for (int it = 0; it < 200; ++it) {
        sink += codes_half_plane_clipper::intersect_half_planes(hps).size();
    }
    auto t1 = std::chrono::steady_clock::now();
    double ns = std::chrono::duration<double, std::nano>(t1 - t0).count() / 200.0;
    std::cout << "half_plane_clipper ns=" << ns << " sink=" << sink << "\n";
    return 0;
}
