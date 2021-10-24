#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "point.h"

class Triangle : public Shape {
 public:
    Point a;
    Point b;
    Point c;

    Triangle(Color color, Point a, Point b, Point c)
        : Shape(color), a(a), b(b), c(c) {}

    void print(std::ostream& stream) override;
    double perimeter() override;
    static Triangle read(Buffer& stream);
};


#endif