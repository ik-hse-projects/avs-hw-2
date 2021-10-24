#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

Shape* Shape::read(Buffer& stream) {
    uint kind = stream.read_uint(1, 4);
    switch (kind) {
        case 1:
            return new Circle(Circle::read(stream));
        case 2:
            return new Rectangle(Rectangle::read(stream));
        case 3:
            return new Triangle(Triangle::read(stream));
        default:
            return nullptr;
    }
}