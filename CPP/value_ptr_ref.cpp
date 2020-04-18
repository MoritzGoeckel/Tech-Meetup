#include <iostream>

class Foo {
   private:
    int a;

   public:
    Foo(int a) : a(a) {}
    int getA() const { return a; }

    Foo& operator=(const Foo& other) {
        a = other.getA();
        return *this;
    }
};

int main() {
    int a(12);
    // int a = 12;

    // Value
    int aval = a;
    std::cout << aval << std::endl;

    // Pointer
    int* aptr = &a;
    std::cout << *aptr << std::endl;

    // Reference
    int& aref = a;
    std::cout << aref << std::endl;

    Foo f(10);

    // Value
    Foo fval = f;
    std::cout << fval.getA() << std::endl;

    // Pointer
    Foo* fptr = &f;
    std::cout << (*fptr).getA() << std::endl;
    std::cout << fptr->getA() << std::endl;

    // Reference
    Foo& fref = f;
    std::cout << fref.getA() << std::endl;
}

/*
Which ones compiles?
    Foo x;
    Foo* x;
    Foo& x;

When should we use values, pointers, or references?
How to init variable depending on condition?
*/

