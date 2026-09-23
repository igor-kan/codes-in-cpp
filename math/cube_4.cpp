#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(4)) == 64);
    std::cout << "PASS cube_4\n";
    return 0;
}
