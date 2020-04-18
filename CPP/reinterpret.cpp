#include <iostream>
#include <vector>

int main() {
    // Writing a uint16_t into a vector of uint8_t
    uint16_t input = 9001;
    std::vector<uint8_t> v;

    // Choosen index
    int index = 0;

    // Writing
    v.reserve(2);
    *reinterpret_cast<uint16_t*>(v.data() + index) = input;

    // Reading
    uint16_t output = *reinterpret_cast<uint16_t*>(v.data() + index);

    std::cout << output << std::endl;  // 9001
}

// reinterpret_cast
// *reinterpret_cast<uint16_t*>(v.data() + index) = input;

// c-style cast
// *((int16*)(v.data() + index)) = input;

// dynamic_cast<>
// static_cast<>
