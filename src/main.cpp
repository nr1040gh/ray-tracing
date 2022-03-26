#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


struct Point
{
    double x, y, z;
    Point(double x = 0, double y = 0, double z = 0)
    : x(x)
    , y(y)
    , z(z)
    {}
    
};

ostream& operator << (ostream& os, Point& p)
{
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
}

double dotProd(vector<double> v1, vector<double> v2)
//So far assumes v1 is same dimensions as v2
//Can template this for any general container
{
    double result = 0;
    for (int i=0; i < v1.size(); i++)
    {
        result += v1[i] * v2[i];
    }
    
    return result;
}


vector<double> unitVec(vector<double> v1)
{
    
    vector<double> unitVec;
    double sqrt_inner = 0, magnitude = 0;
    for (int i=0; i < v1.size(); i++)
    {
        sqrt_inner += v1[i] * v1[i];
        unitVec.push_back(v1[i]);
    }
    
    magnitude = sqrt(sqrt_inner);
    for (int i=0; i < unitVec.size(); i++)
    {
        unitVec[i] = unitVec[i] / magnitude;
    }
    
    return unitVec;
}


double cosSimilarity(vector<double> v1, vector<double> v2)
//Assumes v1 and v2 are same dimensions
//Returns a double between 0 and 1
{
    vector<double> unitVec1 = unitVec(v1);
    vector<double> unitVec2 = unitVec(v2);
    
    double result = dotProd(unitVec1,unitVec2);
    
    return result;
}


vector<double> getVector(Point p1, Point p2)
{
    vector<double> result{ (p2.x - p1.x), (p2.y - p1.y), (p2.z - p1.z) };
    
    return result;
}


void magnitude()
{
    
}


void normalize()
{
    
}


class Display
//zero perspective (orthogonal, rays come out perpendicular to screen)
//rays will come out from center of pixel
//will use left handed 3d coord system: https://www.povray.org/documentation/3.7.0/t2_2.html (pos y up, pos x right, pos z out)
//viewing plane (display) will be z = 0, stretching in the positive x-y plane
{
private:
    const int height;               //height of the viewing screen (terminal)
    const int width;                //width of the viewing screen (terminal)
    double viewing_distance = 100;  //deprecated for now
    
    const double xmin=0, ymin=0;
    const double xmax, ymax;
public:
    Display(const int height, const int width)
    : height(height)
    , width(width)
    , xmax(width)
    , ymax(height)
    {}
    
    const int getHeight() const
    {
        return height;
    }
    
    const int getWidth() const
    {
        return width;
    }
};



class LightSource          //point light source
{
private:
    double x, y, z;
    double theta , phi, r;  //spherical coord system position
    
public:
    LightSource(double x=50.0, double y=80.0, double z=50.0) //cartesian coord system position
    : x(x)
    , y(y)
    , z(z)
    {}
    
    
    vector<double> getLightRay(Point p)
    //Get unit vector of light source to point on sphere
    {
        
        
        return vector<double> { 0.0, 0.0, 0.0 };
    }
    
    
    void setPositionSphere(double theta2, double phi2, double dist_from_sphere)
    //To rotate light source around sphere
    {
        
    }
    
    
    Point getPoint()
    {
        return Point(x,y,z);
    }
    
};


class Sphere
{
private:
    double center_x, center_y, center_z, radius;
    
public:
    Sphere(double radius, double x=50.0, double y=50.0, double z=50.0):
    center_x(x),
    center_y(y),
    center_z(z),
    radius(radius)
    {}
    
    double getX() const
    {
        return center_x;
    }
    
    double getY() const
    {
        return center_y;
    }
    
    double getZ() const
    {
        return center_z;
    }
    
    double getRadius() const
    {
        return radius;
    }
    
    double getSphereZ(Point p)
    //Get and return the z coordinate on the sphere given an x,y coordinate
    //To get point on sphere, use pythagorean theorem: r^2 = x^2 + y^2 + z^2, solve for z
    //account for sphere position r^2 = (x-h)^2 + (y-k)^2 + (z-l)^2
    //z = sqrt( r^2 - (x-h)^2 - (y-k)^2 ) + l
    //Should have 2 answers since it should intersect in two places on sphere, use one closest to viewing plane
    //Here, h,k,l are the center of the sphere in x,y,z
    {
        double sphere_z = 0.0, inner_sqrt = 0.0;
        
        inner_sqrt
        = ( radius * radius )
        - ( (p.x-center_x) * (p.x-center_x) )
        - ( (p.y-center_y) * (p.y-center_y) )
        ;
        
        sphere_z = sqrt(inner_sqrt) + center_z;
        
        return sphere_z;
    }
    
    Point getPoint()
    {
        return Point(center_x,center_y,center_z);
    }
    
};








class RayCast
{
private:
    Display d;
    LightSource l_src;
    Sphere s;
    
public:
    RayCast(Display &d, LightSource &l_src, Sphere &s)
    : d(d)
    , l_src(l_src)
    , s(s)
    {}
    
    vector< vector<double> > cast()
    //Keep as nested or not? Which is more efficient
    {
        int counter = 0;
        double pxl_x, pxl_y, sphere_z;
        bool sphere_hit = 0;
        Point p, sphere_point;
        vector<double> light_sphere_vec, sphere_normal_vec;
        vector< vector<double> > array_vector, light_ray, normal_vec;
        
        
        for (int row_num = 0; row_num < d.getHeight(); row_num++)
        {
            vector<double> row_vector; //to be stored in array vector
            pxl_y = 0.5 + row_num;
            
            for (int col_num = 0; col_num < d.getWidth(); col_num++)
            {
                pxl_x = 0.5 + col_num;
                p.x = pxl_x;
                p.y = pxl_y;
                
                sphere_hit = sphereDetection(p);
                if (sphere_hit)
                {
                    //cout << p << " ";
                    sphere_z = s.getSphereZ(p);
                    sphere_point = Point(p.x,p.y,sphere_z);
                    light_sphere_vec = getVector(sphere_point,l_src.getPoint());
                    
                    //https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
                    //Can simply get normal vec as center point minus intersection point
                    sphere_normal_vec = getVector(sphere_point,s.getPoint());
                    
                    //calculate cossim here with light ray and normal vector and add to vector
                    row_vector.push_back(cosSimilarity(sphere_normal_vec,light_sphere_vec));
                }
                else
                {
                    row_vector.push_back(0.0);
                }
                
                //cout << p << " ";
                
                
                counter++;
            }
            
            //cout << endl;
            array_vector.push_back(row_vector);
        }
        
        //cout << counter << endl;
        return array_vector;
        
    }
    
    bool sphereDetection(Point p)
    //We only need to check if there's a point on the sphere at the x,y coordinates of our pixel's center
    //Check if x,y point lies within cross section of sphere with sphere radius
    //Check if distance from point in x,y to center of sphere is less than or equal to radius
    {
        double d = 0.0, inner_sqrt = 0.0;
        
        inner_sqrt
        = ( (p.x-s.getX())*(p.x-s.getX()) )
        + ( (p.y-s.getY())*(p.y-s.getY()) )
        ;
        
        d = sqrt(inner_sqrt);
        
        if ( d <= s.getRadius())
            return 1;
        else
            return 0;
        
        return 0;
    }
    
};



class PrintGraphics
//
//        00Q@Q00
//     oO000QQQ000Oo
//    ooOOO00Q00OOOoo
//    ooOOO00000OOOoo
//     oooOO000OOooo
//       .--==--.
//
{
private:
    Display d;
    //vector<vector<double>> raw_input;
    const vector<string> chars{ "  ", "..", "--", "==", "oo", "OO", "QQ", "00" }; //.-=oO0Q@
    
public:
    PrintGraphics(Display d):
    d(d)
    //raw_input(raw_input)
    {}
    
    
    void iterateInput(vector< vector<double> > raw_input) const
    //https://stackoverflow.com/questions/19719252/iterating-through-a-2d-vector-row
    //Double for-loop is bad, but using it for now
    //Also hard-coding in character positions, need to clean that up
    //Also using large if-else statements, need to find better way for that -> map?
    //Keep as nested or not? Which is more efficient
    {
        
        for (auto& row : raw_input)
        {
            for (auto& col : row)
            {
                
                //cout << col;
                if ( (col <= 1.0) && (col >= 0.875) )
                {
                    cout << chars[7];
                }
                else if ( (col < 0.875) && (col >= 0.75) )
                {
                    cout << chars[6];
                }
                else if ( (col < 0.75) && (col >= 0.625) )
                {
                    cout << chars[5];
                }
                else if ( (col < 0.625) && (col >= 0.5) )
                {
                    cout << chars[4];
                }
                else if ( (col < 0.5) && (col >= 0.375) )
                {
                    cout << chars[3];
                }
                else if ( (col < 0.375) && (col >= 0.25) )
                {
                    cout << chars[2];
                }
                else if ( (col < 0.25) && (col >= 0.125) )
                {
                    cout << chars[1];
                }
                else if ( (col < 0.125) && (col >= 0.0) )
                {
                    cout << chars[0];
                }
                else
                {
                    cout << chars[0];
                }
                
            }
            
            cout << endl;
        }
    }
    
};





//TODO: normal vectors, create ray vectors, ray collision detection, templatize



int main()
{
    
    //vector< vector<double> > raw_input = { {0.2, 0.0, 0.5, 1.0},
    //                                     {0.51, 0.75, 0.8, 0.6},
    //                                     {0.49, 0.35, 0.45, 1.0},
    //                                     {0.72, 0.15, 0.5, 1.0},
    //                                    };
    
    Display d(150,150);
    Sphere s(21.0);
    //LightSource l_src(20.0,90.0,90.0);
    LightSource l_src(20.0,90.0,30.0);
    PrintGraphics p(d);
    RayCast rc(d, l_src, s);
    
    vector< vector<double> > raw_input = rc.cast();
    p.iterateInput(raw_input);
    cout << "hello" << endl;
    
    return 0;
}
