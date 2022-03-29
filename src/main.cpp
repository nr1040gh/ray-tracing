#include <vector>
#include "point.hpp"
#include "display.hpp"
#include "sphere.hpp"
#include "light_source.hpp"
#include "vector_ops.hpp"
#include "ray_cast.hpp"
#include "print_graphics.hpp"



#include <iostream>////////////////////////////////////////
using namespace std;



void animation(LightSource l_src, Sphere s)
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
        //cout << new_theta << " " << new_phi << endl;

        l_src.revolveLightSource(new_theta,new_phi,s,dist_from_sphere);
        raw_input = rc.cast(l_src);
        p.iterateInput(raw_input);
        
        
            
    }



}






int main()
{
    /*
    Display d(50,80);
    Sphere s(20.0, 40.0, 20.0, 50.0);
    //LightSource l_src(80.0,90.0,00.0);  //screenshot l_src
    LightSource l_src(40.0,20.0,100.0); //Place directly behind sphere, 80 units away from outside of shere
    PrintGraphics p(d);
    RayCast rc(d, l_src, s);
    
    vector< vector<double> > raw_input = rc.cast();
    p.iterateInput(raw_input);
    */

    
    Sphere s(20.0, 40.0, 20.0, 50.0);
    LightSource l_src(40.0,20.0,100.0); //Place directly behind sphere, 30 units away from outside of shere
    //LightSource l_src(40.0,20.0,130.0); //Place directly in front sphere, 30 units away from outside of shere
    
    
    animation(l_src,s);
    
    return 0;
}
