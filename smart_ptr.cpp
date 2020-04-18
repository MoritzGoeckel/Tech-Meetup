#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> a = std::make_unique<int>(42);
    {
        std::unique_ptr<int> b = std::make_unique<int>(43);
        std::cout << *b << std::endl;
    }
    std::cout << *a << std::endl;
    {
        std::unique_ptr<int> c = std::make_unique<int>(44);
        std::cout << *c << std::endl;
    }

    // Whats on the stack and what is on the heap?

    // std::unique_ptr<int> d = a;
    std::unique_ptr<int> d = std::move(a);

    std::shared_ptr<int> e = std::make_shared<int>(45);
    {
        auto f = e;
        std::cout << *f << std::endl;
    }
}
