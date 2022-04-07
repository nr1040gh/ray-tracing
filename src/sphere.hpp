#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "point.hpp"


/**
 * A sphere light source class
 */
class Sphere
{
private:
    double center_x, center_y, center_z, radius;
    
public:

    //Initialize with x,y,z cartesian coordinates, defaults provided.
    Sphere(double radius, double x=50.0, double y=50.0, double z=50.0);
    
    double getX() const;
    double getY() const;
    double getZ() const;
    double getRadius() const;
    

    /**
     * @brief Get the z coordinate on sphere given x,y coordinate point. Returns "smallest" z coordinate
     * 
     * @param p         Point p in x,y,z coordinates. Use x,y to find given sphere surface z
     * 
     * @return double   Sphere surface z coordinate value
     */
    double getSphereZ(Point p);
    

     /**
     * @brief Return a Point object made up of sphere's center cartesian coordinates
     * 
     * @return Point
     */
    Point getPoint();
    
};

#endif