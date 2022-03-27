#include <iostream>
#include "point.hpp"
using namespace std;

Point::Point(double x, double y, double z)
    : x(x)
    , y(y)
    , z(z)
    {}


ostream& operator << (ostream& os, Point& p) //TODO: CHECK THIS FOR HEADER FILE!
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}