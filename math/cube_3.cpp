#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(3)) == 27);
    std::cout << "PASS cube_3\n";
    return 0;
}
