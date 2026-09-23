#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(1)) == 1);
    std::cout << "PASS cube_1\n";
    return 0;
}
