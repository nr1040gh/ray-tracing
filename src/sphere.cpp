#include <cmath>
#include "point.hpp"
#include "sphere.hpp"

using namespace std;

Sphere::Sphere(double radius, double x, double y, double z):
    center_x(x),
    center_y(y),
    center_z(z),
    radius(radius)
    {}
    

double Sphere::getX() const
{
    return center_x;
}


double Sphere::getY() const
{
    return center_y;
}


double Sphere::getZ() const
{
    return center_z;
}


double Sphere::getRadius() const
{
    return radius;
}


double Sphere::getSphereZ(Point p)
//Get and return the z coordinate on the sphere given an x,y coordinate
//To get point on sphere, use pythagorean theorem: r^2 = x^2 + y^2 + z^2, solve for z
//account for sphere position r^2 = (x-h)^2 + (y-k)^2 + (z-l)^2
//z = sqrt( r^2 - (x-h)^2 - (y-k)^2 ) + l
//Should have 2 answers since it should intersect in two places on sphere, use one closest to viewing plane
//Here, h,k,l are the center of the sphere in x,y,z
{
    double sphere_z = 0.0, inner_sqrt = 0.0;
    
    inner_sqrt
    = ( radius * radius )
    - ( (p.x-center_x) * (p.x-center_x) )
    - ( (p.y-center_y) * (p.y-center_y) )
    ;
    
    sphere_z = sqrt(inner_sqrt) + center_z;
    
    return sphere_z;
}


Point Sphere::getPoint()
{
    return Point(center_x,center_y,center_z);
}