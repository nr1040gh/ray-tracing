#ifndef RAY_CAST_HPP
#define RAY_CAST_HPP

#include <vector>
#include "point.hpp"
#include "sphere.hpp"
#include "display.hpp"
#include "light_source.hpp"
#include "vector_ops.hpp"

class RayCast
{
private:
    Display d;
    LightSource l_src;
    Sphere s;
    
public:
    RayCast(Display &d, LightSource &l_src, Sphere &s);
    
    std::vector< std::vector<double> > cast();
    
    bool sphereDetection(Point p);
    
};

#endif