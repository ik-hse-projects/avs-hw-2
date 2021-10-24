#include "triangle.h"

void Triangle::print(std::ostream& stream) {
    stream << "Triangle: ";
    Shape::print(stream);
    stream << ", a=";
    a.print(stream);
    stream << ", b=";
    b.print(stream);
    stream << ", c=";
    c.print(stream);
}

double Triangle::perimeter() {
    return a.distance(b) + b.distance(c) + c.distance(a);
}

Triangle Triangle::read(Buffer& stream) {
    Color color = Color::read(stream);
    Point a = Point::read(stream);
    Point b = Point::read(stream);
    Point c = Point::read(stream);
    return Triangle(color, a, b, c);
}
