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
/**
 * @brief Get the z coordinate on sphere given x,y coordinate point
 * Can yield 2 different z coordinates depending on how equation is framed, in this case we always choose the "lower" z value since its closest to screen
 * 
 * To get point on sphere, use pythagorean theorem: r^2 = x^2 + y^2 + z^2, solve for z
 * Account for sphere position r^2 = (x-h)^2 + (y-k)^2 + (z-l)^2. Solve for z: z = sqrt( r^2 - (x-h)^2 - (y-k)^2 ) + l
 * Here, h,k,l are the center of the sphere in x,y,z
 */
{
    double sphere_z = 0.0, inner_sqrt = 0.0;
    
    inner_sqrt
    = ( radius * radius )
    - ( (p.x-center_x) * (p.x-center_x) )
    - ( (p.y-center_y) * (p.y-center_y) )
    ;
    

    //Update this when multiple spheres (reflection) is added to choose correct sphere_z value accordingly
    //sphere_z = sqrt(inner_sqrt) + center_z;   //THIS GIVES US THE POINT ON THE SPHERE FURTHEST FROM US (positive z direction from center)
    sphere_z = center_z - sqrt(inner_sqrt);     //WE WANT THE POINT CLOSEST TO THE VIEWING SECTION (NEGATIVE Z DIRECTION FROM CENTER)

    return sphere_z;
}


Point Sphere::getPoint()
{
    return Point(center_x,center_y,center_z);
}