#include "color.h"

Color Color::read(Buffer& stream) {
    uint value = stream.read_uint(1, MAX_COLOR);
    if (value >= MAX_COLOR) {
        return Color(RED);
    }
    return Color(static_cast<Value>(value));
}

void Color::print(std::ostream& stream) {
    switch (value) {
        case RED:
            stream << "red";
            break;
        case ORANGE:
            stream << "orange";
            break;
        case YELLOW:
            stream << "yellow";
            break;
        case GREEN:
            stream << "green";
            break;
        case LIGHT_BLUE:
            stream << "light blue";
            break;
        case BLUE:
            stream << "blue";
            break;
        case PURPLE:
            stream << "purple";
            break;
        default:
            stream << "unknown color";
            break;
    }
}
