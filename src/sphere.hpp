#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "point.hpp"


class Sphere
{
private:
    double center_x, center_y, center_z, radius;
    
public:
    Sphere(double radius, double x=50.0, double y=50.0, double z=50.0);
    
    double getX() const;
    
    double getY() const;
    
    double getZ() const;
    
    double getRadius() const;
    
    double getSphereZ(Point p);
    
    Point getPoint();
    
};

#endif