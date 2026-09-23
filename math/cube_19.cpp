#include <cassert>
#include <iostream>

unsigned long long cube(int n){ return (unsigned long long)n*n*n; }

int main() {
    assert((cube(19)) == 6859);
    std::cout << "PASS cube_19\n";
    return 0;
}
