#include <iostream>

class Foo {
   private:
    int a;

   public:
    Foo() : a(1337) { std::cout << "Standard constructor" << std::endl; }

    Foo(int a) : a(a * 10) { std::cout << "Int constructor" << std::endl; }

    virtual void doSomething() { std::cout << "Foo!" << std::endl; }

    void doAnotherThing() { std::cout << "Another Foo!" << std::endl; }
};

class Bar : public Foo {
   public:
    Bar() : Foo(42) {}
    virtual void doSomething() { std::cout << "Bar!" << std::endl; }
    void doAnotherThing() { std::cout << "Another Bar!" << std::endl; }
};

int main() {
    // One of them is bad
    Foo a;
    Foo b();
    Foo c(10);
    Foo d = 10;

    c.doSomething();
    c.doAnotherThing();

    Bar e;
    e.doSomething();
    e.doAnotherThing();

    Foo* f = static_cast<Foo*>(&e);
    f->doSomething();
    f->doAnotherThing();
}
