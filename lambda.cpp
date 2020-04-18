#include <functional>
#include <iostream>

std::function<void(int)> getLambda() {
    int b = 10;
    return [&](int a) { std::cout << "Lambda: " << a * b << std::endl; };
}

int main() {
    auto x = getLambda();
    x(2);
    return 0;
}
