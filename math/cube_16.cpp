#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(16)) == 4096);
    std::cout << "PASS cube_16\n";
    return 0;
}
