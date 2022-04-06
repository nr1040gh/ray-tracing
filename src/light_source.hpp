#ifndef LIGHT_SOURCE_HPP
#define LIGHT_SOURCE_HPP

#include <vector>
#include "point.hpp"
#include "sphere.hpp"


/**
 * A point light source class
 */
class LightSource
{
private:
    double x, y, z;         // cartesian coord system position
    double theta , phi, r;  //spherical coord system position
    
public:

    //Initialize with x,y,z cartesian coordinates, defaults provided.
    LightSource(double x=50.0, double y=80.0, double z=50.0);
    
        
    //deprecated
    void setPositionSphere(double theta2, double phi2, double dist_from_sphere);


    /**
     * @brief Set the position of the light source around a sphere given new theta and phi and a distance from outside of sphere
     * Physics convention (azimuthal is phi, polar is theta), still in left handed, z-out coordinate system (swap y and z in typical z-up right handed coordinate system)
     * 
     * @param theta2            The new theta position around sphere center (degrees) theta=0 -> point completely in pos. y axis | theta=90 -> completely perpendicular to y axis
     * @param phi2              The new phi position around sphere center   (degrees) phi=0 -> point completely in pos. x axis | phi=90 -> completely perpendicular to x axis, point completely in pos. z axis
     * @param s                 Sphere which the light source will revolve around
     * @param dist_from_sphere  Distance from the outside of the sphere which the light source will be positioned at
     */
    void revolveLightSource(double theta2, double phi2, Sphere s, double dist_from_sphere);
    

    double getX();
    double getY();
    double getZ();

    /**
     * @brief Return a Point object made up of light source's cartesian coordinates
     * 
     * @return Point
     */
    Point getPoint();
    
};

std::ostream& operator << (std::ostream& os, Point& p);

#endif