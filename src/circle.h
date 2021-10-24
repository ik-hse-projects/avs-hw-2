#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "point.h"

class Circle : public Shape {
 public:
    Point center;
    uint radius;

    Circle(Color color, Point center, uint radius)
        : Shape(color), center(center), radius(radius) {}

    void print(std::ostream& stream) override;

    double perimeter() override;

    static Circle read(Buffer& stream);
};

#endif