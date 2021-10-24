#ifndef SHAPE_H
#define SHAPE_H

#include "color.h"
#include "buffer.h"

class Shape {
 public:
    Color color;

    Shape(Color color) : color(color) {}

    static Shape* read(Buffer& stream);
    virtual void print(std::ostream& stream) {
        stream << "color = ";
        color.print(stream);
    }
    virtual double perimeter() = 0;
};

#endif