#include <functional>
#include <iostream>

std::function<void(int)> getLambda() {
    int b = 10;
    return [&](int a) { std::cout << "Lambda: " << a * b << std::endl; };
}

int main() {
    auto x = getLambda();

    // Allocate a kb and clean up
    auto f = new char[1024];
    delete[] f;

    x(2);

    return 0;
}
