#include <vector>
#include "point.hpp"
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


Point LightSource::getPoint()
{
    return Point(x,y,z);
}