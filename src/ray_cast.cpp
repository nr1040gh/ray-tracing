#include <vector>
#include <cmath>
#include "point.hpp"
#include "sphere.hpp"
#include "display.hpp"
#include "light_source.hpp"
#include "vector_ops.hpp"
#include "ray_cast.hpp"
using namespace std;


RayCast::RayCast(Display &d, Sphere &s)
    : d(d)
    , s(s)
    {}
    

vector< vector<double> > RayCast::cast(LightSource l_src)
//Keep as nested or not? Which is more efficient
{
    int counter = 0;
    double pxl_x, pxl_y, sphere_z;
    bool sphere_hit = 0;
    Point p, sphere_point;
    vector<double> light_sphere_vec, sphere_normal_vec;
    vector< vector<double> > array_vector, light_ray, normal_vec;
    
    
    for (int row_num = d.getHeight(); row_num >= 0; row_num--)
    {
        vector<double> row_vector; //to be stored in array vector
        pxl_y = 0.5 + row_num;
        
        for (int col_num = 0; col_num <= d.getWidth(); col_num++)
        {
            //cout << col_num << " ";
            pxl_x = 0.5 + col_num;
            p.x = pxl_x;
            p.y = pxl_y;
            
            sphere_hit = sphereDetection(p);
            if (sphere_hit)
            {
                //cout << p << " ";
                sphere_z = s.getSphereZ(p);
                sphere_point = Point(p.x,p.y,sphere_z);
                
                
                //https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
                //Can simply get normal vec as center point minus intersection point
                //sphere_normal_vec = vector_ops::getVector(s.getPoint(),sphere_point);    //inverted y on sphere, inverted x on light source
                //light_sphere_vec = vector_ops::getVector(l_src.getPoint(),sphere_point); //inverted y on sphere, inverted x on light source

                //sphere_normal_vec = vector_ops::getVector(sphere_point,s.getPoint());      //inverted y on sphere, inverted x on light source 
                //light_sphere_vec = vector_ops::getVector(sphere_point,l_src.getPoint());   //inverted y on sphere, inverted x on light source

                sphere_normal_vec = vector_ops::getVector(s.getPoint(),sphere_point);      //inverted z on light source,
                light_sphere_vec = vector_ops::getVector(sphere_point,l_src.getPoint());   //inverted z on light source,

                //sphere_normal_vec = vector_ops::getVector(sphere_point,s.getPoint());      //inverted y,z on sphere, inverted y,z on light source,
                //light_sphere_vec = vector_ops::getVector(l_src.getPoint(),sphere_point);   //inverted y,z on sphere, inverted y,z on light source,
                
                //calculate cossim here with light ray and normal vector and add to vector
                row_vector.push_back(vector_ops::cosSimilarity(sphere_normal_vec,light_sphere_vec));
                //cout << vector_ops::cosSimilarity(sphere_normal_vec,light_sphere_vec) << "| ";
            }
            else
            {
                row_vector.push_back(0.0);
            }
            
            //cout << p << " ";
            
            
            counter++;
        }
        
        array_vector.push_back(row_vector);
    }
    
    return array_vector;
    
}
    

bool RayCast::sphereDetection(Point p)
//We only need to check if there's a point on the sphere at the x,y coordinates of our pixel's center
//Check if x,y point lies within cross section of sphere with sphere radius
//Check if distance from point in x,y to center of sphere is less than or equal to radius
{
    double dist = 0.0, inner_sqrt = 0.0;
    
    inner_sqrt
    = ( (p.x-s.getX())*(p.x-s.getX()) )
    + ( (p.y-s.getY())*(p.y-s.getY()) )
    ;
    
    dist = sqrt(inner_sqrt);
    
    if ( dist <= s.getRadius())
        return 1;
    else
        return 0;
    
    return 0;
}