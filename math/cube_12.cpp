#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(12)) == 1728);
    std::cout << "PASS cube_12\n";
    return 0;
}
