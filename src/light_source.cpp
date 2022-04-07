#include <cmath>
#include <vector>
#include "point.hpp"
#include "sphere.hpp"
#include "light_source.hpp"
using namespace std;


//cartesian coord system position
LightSource::LightSource(double x, double y, double z) 
    : x(x)
    , y(y)
    , z(z)
    {}
    
    
void LightSource::setPositionSphere(double theta2, double phi2, double dist_from_sphere)
//To rotate light source around sphere
{
    
}


void LightSource::revolveLightSource(double theta2, double phi2, Sphere s, double dist_from_sphere)
/**
 * Coordinate change:
 * https://en.wikipedia.org/wiki/Spherical_coordinate_system
 * x = rcos(phi)sin(theta)
 * z = rsin(phi)sin(theta)
 * y = rcos(theta)
 * 
 * Take theta and phi as degrees, change to radians here
 */
{
    double new_x, new_y, new_z;
    double rad_conversion = M_PI / 180.0;

    theta2 = theta2 * rad_conversion;
    phi2 = phi2 * rad_conversion;

    //r from above equations is distance from sphere + the sphere radius to account for the light source revolving a set distance around center of sphere
    new_x = s.getX() + ( (dist_from_sphere + s.getRadius()) * cos(phi2) * sin(theta2) ); 
    new_y = s.getY() + ( (dist_from_sphere + s.getRadius()) * cos(theta2) );
    new_z = s.getZ() + ( (dist_from_sphere + s.getRadius()) * sin(phi2) * sin(theta2) );

    x = new_x;
    y = new_y;
    z = new_z;
}


Point LightSource::getPoint()
{
    return Point(x,y,z);
}


double LightSource::getX()
{
    return x;
}


double LightSource::getY()
{
    return y;
}


double LightSource::getZ()
{
    return z;
}


ostream& operator << (ostream& os, LightSource& l_src) //TODO: Why shouldnt LightSource be LightSource::LightSource like above? 
//THIS DOESN'T WORK! FIX THIS
{
    os << "(" << l_src.getX() << ", " << l_src.getY() << ", "  << l_src.getZ() << ")";
    return os;
}