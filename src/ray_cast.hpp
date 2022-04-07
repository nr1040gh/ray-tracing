#ifndef RAY_CAST_HPP
#define RAY_CAST_HPP

#include <vector>
#include "point.hpp"
#include "sphere.hpp"
#include "display.hpp"
#include "light_source.hpp"
#include "vector_ops.hpp"

/**
 * A RayCast class
 */
class RayCast
{
private:
    Display d; 
    Sphere s;       //Should remove dependance on Sphere once we introduce multiple, should create method that accepts instead 
    
public:

    //Initialize with viewing screen/display and sphere
    RayCast(Display &d, Sphere &s);


    /**
     * @brief Shoots ray from center of each pixel on viewing screen. 
     * Zero perspective (orthogonal, rays come out perpendicular to screen)
     * Returns brightness result for each pixel on screen. 
     * 
     * @param l_src     Point light source used to trace ray from screen to it after reflecting off sphere
     * @return std::vector< std::vector<double> >   Returns pixel results for pixel. Results contained in rows with top row vector at the "top" of the containing vector
     */
    std::vector< std::vector<double> > cast(LightSource l_src);
    

    /**
     * @brief Uses naive collision detection of ray from screen to sphere in space. 
     * Since ray casted x,y plane down z axis, check if distance from sphere center in x,y plane is less than or equal to sphere radius.
     * If it is, then register as hit, dont register otherwise
     * Will need to be updated when dealing with multiple spheres (reflection) and when perspective is added
     * 
     * @param p         The pixel coordinate from where the ray is casted from, dont care about z, only x,y in this use case
     * @return true     Return true (1) if x,y point distance from sphere center x,y cross section is less than or equal to sphere radius
     * @return false    Return flase (0) if x,y point distance from sphere center x,y cross section is greater than sphere radius
     */
    bool sphereDetection(Point p);
    
};

#endif