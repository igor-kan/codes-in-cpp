#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(2)) == 8);
    std::cout << "PASS cube_2\n";
    return 0;
}
