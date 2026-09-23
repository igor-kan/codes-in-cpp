#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(8)) == 512);
    std::cout << "PASS cube_8\n";
    return 0;
}
