#include <algorithm>
#include <iostream>
#include <string>

class FBool {
   private:
    float state;

   public:
    FBool(const float& value) { this->state = value; }
    FBool(const bool& value) { this->state = value ? 1 : 0; }

    FBool(const FBool& value) { this->state = value.state; }

    FBool& operator=(const bool& value) {
        this->state = value ? 1 : 0;
        return *this;
    }
    FBool& operator=(const FBool& value) {
        this->state = value.state;
        return *this;
    }
    FBool& operator=(const float& value) {
        this->state = value;
        return *this;
    }

    FBool operator&&(const FBool& value) const {
        return FBool(std::min(this->state, value.state));  // Alternative: x*y
    }
    FBool operator||(const FBool& value) const {
        return FBool(
            std::max(this->state, value.state));  // Alternative: x+y-x*y
    }
    FBool operator!() const { return FBool(1 - this->state); }
    bool getBool() const { return this->state > 0.5; }
    float getFloat() const { return this->state; }
};

std::ostream& operator<<(std::ostream& os, const FBool& value) {
    if (value.getBool())
        os << "T(";
    else
        os << "F(";
    os << value.getFloat();
    os << ")";

    return os;
}

int main() {
    FBool t = true;
    FBool f = 0.3f;

    FBool x = t && f;
    FBool y = t || f;
    FBool z = t && !f;

    std::cout << "t=" << t << " f=" << f << std::endl;
    std::cout << "x=" << x << " y = " << y << " z = " << z << std::endl;

    // t=T(1) f=F(0.3)
    // x=F(0.3) y = T(1) z = T(0.7)
}
