#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(15)) == 3375);
    std::cout << "PASS cube_15\n";
    return 0;
}
