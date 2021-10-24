#include <cmath>
#include <climits>

#include "circle.h"

void Circle::print(std::ostream& stream) {
    stream << "Circle: ";
    Shape::print(stream);
    stream << ", center=";
    center.print(stream);
    stream << ", radius=" << radius;
}

double Circle::perimeter() {
    return 2 * M_PI * static_cast<double>(radius);
}

Circle Circle::read(Buffer& stream) {
    Color color = Color::read(stream);
    Point center = Point::read(stream);
    uint radius = stream.read_uint(0, UINT_MAX);
    return Circle(color, center, radius);
}