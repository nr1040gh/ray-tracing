#include <iostream>
#include "point.hpp"
using namespace std;


Point::Point(double x, double y, double z)
    : x(x)
    , y(y)
    , z(z)
    {}


//Overload "<<" operator for debugging
//https://stackoverflow.com/questions/47083328/operator-overloading-in-header-files-and-in-the-cpp-files
ostream& operator << (ostream& os, Point& p) //TODO: Why shouldnt Point be Point::Point like above?
{
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
}