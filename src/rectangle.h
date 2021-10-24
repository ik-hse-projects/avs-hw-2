#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "point.h"

class Rectangle : public Shape {
 public:
    Point top_left;
    Point bottom_right;

    Rectangle(Color color, Point tl, Point br)
        : Shape(color), top_left(tl), bottom_right(br) {}

    void print(std::ostream& stream) override;
    double perimeter() override;
    static Rectangle read(Buffer& stream);
};

#endif