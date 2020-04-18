#include <iostream>

int main() {
    int a = 10;
    int* b = new int(10);

    std::cout << a << std::endl;
    std::cout << *b << std::endl;

    // Why put things on the heap?

    delete b;
}
