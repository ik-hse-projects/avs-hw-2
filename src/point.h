#ifndef POINT_H
#define POINT_H

#include "buffer.h"

class Point {
 public:
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    static Point read(Buffer& stream);

    void print(std::ostream& stream);

    double distance(Point other);
};

#endif