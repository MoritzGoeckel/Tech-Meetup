#include <iostream>
#include <optional>

//#define ENABLE_LOGGING

#ifdef ENABLE_LOGGING
#define LOG(MSG) std::cout << MSG << std::endl
#else
#define LOG(MSG)
#endif

int main() {
    auto a = std::optional<int>(10);
    auto b = std::optional<int>(11);
    auto c = std::optional<int>(11);

#define OUT(VAR) \
    if (VAR) std::cout << #VAR << " is " << *a << std::endl

    OUT(a);
    OUT(b);
    OUT(c);

    for (int i = 0; i < 10; ++i) {
        // do some busy work
        LOG("This is a log message");
    }
}

// g++ -std=c++17 -D ENABLE_LOGGING preprocessor.cpp
