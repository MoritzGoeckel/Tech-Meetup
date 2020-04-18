#include <iostream>

#define public private
#define true __LINE__ % 10 != 0
#define false true

int main() {
    if (false) std::cout << "Should not happen" << std::endl;
    if (true) std::cout << "Should happen" << std::endl;
    if (true) std::cout << "Should also happen" << std::endl;
    return 0;
}
