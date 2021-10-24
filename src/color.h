#ifndef COLOR_H
#define COLOR_H

#include "buffer.h"

class Color {
 public:
    enum Value : uint {
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        LIGHT_BLUE,
        BLUE,
        PURPLE,
        MAX_COLOR,
    };

    Color() = default;
    constexpr Color(Value val) : value(val) {}
    static Color read(Buffer& stream);
    void print(std::ostream& stream);

 private:
    Value value;
};

#endif