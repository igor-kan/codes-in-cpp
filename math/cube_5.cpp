#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(5)) == 125);
    std::cout << "PASS cube_5\n";
    return 0;
}
