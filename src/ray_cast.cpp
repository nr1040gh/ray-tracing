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
//Keep as nested or not? Which is more efficient?
{
    double pxl_x, pxl_y, sphere_z;
    bool sphere_hit = 0;
    Point p, sphere_point;
    vector<double> light_sphere_vec, sphere_normal_vec;
    vector< vector<double> > array_vector, light_ray, normal_vec;
    
    //Start at the height of the top of the viewing screen and work way toward bottom
    for (int row_num = d.getHeight(); row_num >= 0; row_num--)
    {
        vector<double> row_vector; //vector containing all the pixel values for that row
        pxl_y = 0.5 + row_num;     //Shoot ray from center of pixel

        //Work from left to right
        for (int col_num = 0; col_num <= d.getWidth(); col_num++)
        {
            pxl_x = 0.5 + col_num;  //Shoot ray from center of pixel
            p.x = pxl_x;
            p.y = pxl_y;
            
            //zero perspective (orthogonal, rays come out perpendicular to screen) - can think of ray coming out of screen as x,y point projected down z zxis
            sphere_hit = sphereDetection(p);
            if (sphere_hit)
            {
                sphere_z = s.getSphereZ(p);
                sphere_point = Point(p.x,p.y,sphere_z);
                
                
                //https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
                //Can simply get normal vec as center point minus intersection point
                sphere_normal_vec = vector_ops::getVector(s.getPoint(),sphere_point);      
                light_sphere_vec = vector_ops::getVector(sphere_point,l_src.getPoint());   
                
                //calculate cossim here with light ray and normal vector and add to vector
                row_vector.push_back(vector_ops::cosSimilarity(sphere_normal_vec,light_sphere_vec));
            }
            else
            {
                row_vector.push_back(0.0);
            }
                        
        }
        
        array_vector.push_back(row_vector);
    }
    
    return array_vector;
    
}
    

bool RayCast::sphereDetection(Point p)
/**
 * @brief Since we send rays "directly" at sphere, to check hit detection, only need to see if x,y coord is within x,y cross-section of sphere
 * To do this, check if distance from sphere center in x,y plane is less than sphere radius
 * 
 */
{
    double dist = 0.0, inner_sqrt = 0.0;
    
    //dist = sqrt( (x1-x2)^2 + (y1-y2)^2 )
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