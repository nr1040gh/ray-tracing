#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

struct Point
{
public:
    double x, y, z;
    Point(double x = 0, double y = 0, double z = 0);
};

//https://stackoverflow.com/questions/47083328/operator-overloading-in-header-files-and-in-the-cpp-files
std::ostream& operator << (std::ostream& os, Point& p);

#endif
