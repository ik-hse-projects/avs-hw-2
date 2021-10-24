#include <climits>
#include <cmath>

#include "point.h"

Point Point::read(Buffer& stream) {
    int x = stream.read_int(0, INT_MAX);
    int y = stream.read_int(0, INT_MAX);
    return Point(x, y);
}

void Point::print(std::ostream& stream) { stream << "(" << x << ", " << y << ")"; }

double Point::distance(Point other) {
    int dx = other.x - x;
    int dy = other.y - y;
    return std::sqrt((double)(dx * dx + dy * dy));
}
