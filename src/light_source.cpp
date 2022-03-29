#include <cmath>
#include <vector>
#include "point.hpp"
#include "sphere.hpp"
#include "light_source.hpp"
using namespace std;

LightSource::LightSource(double x, double y, double z) //cartesian coord system position
    : x(x)
    , y(y)
    , z(z)
    {}
    
    
void LightSource::setPositionSphere(double theta2, double phi2, double dist_from_sphere)
//To rotate light source around sphere
{
    
}


void LightSource::revolveLightSource(double theta2, double phi2, Sphere s, double dist_from_sphere)
//To rotate light source around sphere
//Take theta and phi as degrees, change to radians here
//physics convention (azimuthal is phi, polar is theta), still in left handed, z-out coordinate system (swap y and z in typical z-up right handed coordinate system)
//theta=0 -> point completely in y axis
//theta=pi/2 -> completely perpendicular to y axis
//phi=0 -> point completely in x axis
//phi=pi/2 -> completely perpendicular to z axis, point completely in z axis
//x = rcos(phi)sin(theta)
//z = rsin(phi)sin(theta)
//y = rcos(theta)
//https://en.wikipedia.org/wiki/Spherical_coordinate_system

{
    double new_x, new_y, new_z;
    double rad_conversion = M_PI / 180.0;

    theta2 = theta2 * rad_conversion;
    phi2 = phi2 * rad_conversion;

    new_x = s.getX() + ( (dist_from_sphere + s.getRadius()) * cos(phi2) * sin(theta2) ); //add center_x here?
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

ostream& operator << (ostream& os, LightSource& l_src) //TODO: Why should Point be Point::Point like above? 
//THIS DOESN'T WORK! FIX THIS
{
    os << "(" << l_src.getX() << ", " << l_src.getY() << ", "  << l_src.getZ() << ")";
    return os;
}