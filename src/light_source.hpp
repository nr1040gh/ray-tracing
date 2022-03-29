#ifndef LIGHT_SOURCE_HPP
#define LIGHT_SOURCE_HPP

#include <vector>
#include "point.hpp"
#include "sphere.hpp"

class LightSource          //point light source
{
private:
    double x, y, z;
    double theta , phi, r;  //spherical coord system position
    
public:
    LightSource(double x=50.0, double y=80.0, double z=50.0);
    
    
    std::vector<double> getLightRay(Point p);
    
    
    void setPositionSphere(double theta2, double phi2, double dist_from_sphere);


    void revolveLightSource(double theta2, double phi2, Sphere s, double dist_from_sphere);
    

    double getX();


    double getY();


    double getZ();

    
    Point getPoint();
    
};

std::ostream& operator << (std::ostream& os, Point& p);

#endif