#include "rectangle.h"

void Rectangle::print(std::ostream& stream) {
    stream << "Rectangle: ";
    Shape::print(stream);
    stream << ", top-left=";
    top_left.print(stream);
    stream << ", bottom-right=";
    bottom_right.print(stream);
}

double Rectangle::perimeter() {
    int height = bottom_right.y - top_left.y;
    int width = bottom_right.x - top_left.x;
    return (height + width) * 2;
}

Rectangle Rectangle::read(Buffer& stream) {
    Color color = Color::read(stream);
    Point top_left = Point::read(stream);
    Point bottom_right = Point::read(stream);
    return Rectangle(color, top_left, bottom_right);
}
