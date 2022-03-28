#include <vector>
#include "point.hpp"
#include "display.hpp"
#include "sphere.hpp"
#include "light_source.hpp"
#include "vector_ops.hpp"
#include "ray_cast.hpp"
#include "print_graphics.hpp"
using namespace std;


int main()
{
    Display d(90,90);
    Sphere s(21.0);
    //LightSource l_src(20.0,90.0,90.0);
    LightSource l_src(20.0,90.0,30.0);
    PrintGraphics p(d);
    RayCast rc(d, l_src, s);
    
    vector< vector<double> > raw_input = rc.cast();
    p.iterateInput(raw_input);
    
    return 0;
}
