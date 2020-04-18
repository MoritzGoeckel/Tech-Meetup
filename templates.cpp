#include <iostream>

template <typename T>
class Optional {
   private:
    T value;
    bool isPresent;

   public:
    Optional(T value) : value(value), isPresent(true) {}
    Optional() : value(), isPresent(false) {}

    bool getIsPresent() const noexcept { return isPresent; }

    T get() const {
        if (!getIsPresent()) throw;
        return value;
    }

    T operator*() { return get(); }
};

int main() {
    auto a = Optional<int>(10);
    auto b = Optional<int>();

    if (a.getIsPresent()) std::cout << *a << std::endl;
    if (b.getIsPresent()) std::cout << *b << std::endl;

    return 0;
}
