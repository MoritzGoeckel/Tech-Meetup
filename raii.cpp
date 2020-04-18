#include <cstring>
#include <iostream>
#include <vector>

// Resource Acquisition Is Initialization
class Vector {
   private:
    char* data;
    size_t size;

   public:
    Vector() : data(new char[10]), size(10) {
        // the constructor acquires the resource
    }

    void resize(size_t new_size) {
        char* new_data = new char[new_size];
        std::memcpy(new_data, data, size);
        delete data;
        data = new_data;
        size = new_size;
    }

    ~Vector() {
        // the destructor releases the resource
        delete data;
    }
};

int main() {
    Vector vec;
    std::cout << "Sizeof vec=" << sizeof(vec) << std::endl;
    vec.resize(100);
    std::cout << "Sizeof vec=" << sizeof(vec) << std::endl;

    std::vector<uint32_t> stdvec;
    std::cout << "Sizeof stdvec=" << sizeof(stdvec) << std::endl;

    stdvec.resize(100);
    std::cout << "Sizeof stdvec=" << sizeof(stdvec) << std::endl;

    // What is the output?

    return 0;
};
