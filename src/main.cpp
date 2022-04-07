#include <vector>
#include "point.hpp"
#include "display.hpp"
#include "sphere.hpp"
#include "light_source.hpp"
#include "vector_ops.hpp"
#include "ray_cast.hpp"
#include "print_graphics.hpp"
using namespace std;


void animation(LightSource l_src, Sphere s)
/**
 * @brief Animate the light source revolving around the sphere and update the terminal display to show the results
 *      Animate by changing the phi and theta spherical coordinates of the light source and calculate and update the x,y,z coordinates
 *      Animates until program is killed
 * 
 * @param l_src    Global point light source that will have its position updated
 * @param s        The sphere which we are casting the rays at
 */
{
    double x_start = l_src.getX();
    double y_start = l_src.getY();
    double z_start = l_src.getZ();

    double new_phi = 90.0;
    double new_theta = 90.0;
    double dist_from_sphere = 60.0;

    Display d(50,80);
    RayCast rc(d, s);
    PrintGraphics p(d);

    vector< vector<double> > raw_input;

    l_src.revolveLightSource(new_theta,new_phi,s,dist_from_sphere);
    raw_input = rc.cast(l_src);
    p.iterateInput(raw_input);

    while(1)
    {
        new_phi += 1.25;
        new_theta += 2.0;
        if (new_phi > 360.0)
        {
            new_phi -= 360;
        }

        if (new_theta > 360.0)
        {
            new_theta -= 360;
        }

        l_src.revolveLightSource(new_theta,new_phi,s,dist_from_sphere);
        raw_input = rc.cast(l_src);
        p.iterateInput(raw_input);        
    }

}


int main()
{ 
    Sphere s(20.0, 40.0, 20.0, 50.0);
    LightSource l_src(40.0,20.0,100.0); //Place directly behind sphere, 30 units away from outside of shere    
    
    animation(l_src,s);
    
    return 0;
}
