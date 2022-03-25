#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


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


class LightSource           //point light source
{
private:
    double x, y, z;         //cartesian coord system position
    double theta , phi, r;  //spherical coord system position
    

    //void setPositionSphere(theta2,phi2,dist_from_sphere);

};


class Sphere
{
private:
    double x, y, z, radius;

public:
    Sphere(double radius, double x=50.0, double y=50.0, double z=50.0):
    x(x),
    y(y),
    z(z),
    radius(radius)
    {}

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }

    double getZ() const
    {
        return z;
    }

    double getRadius() const
    {
        return radius;
    }

};



struct Point
{
    double x=0.0, y=0.0, z=0.0;
};

ostream& operator << (ostream& os, Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}


class RayCast
{
private:
    Display d;
    LightSource l_src;
    Sphere s;

public:
    RayCast(Display d, LightSource l_src, Sphere s)
    : d(d)
    , l_src(l_src)
    , s(s)
    {}

    vector<double> cast()
    {
        int counter = 0;
        double pxl_x, pxl_y;
        Point p;

        for (int row_num = 0; row_num < d.getHeight(); row_num++)
        {
            pxl_y = 0.5 + row_num;

            for (int col_num = 0; col_num < d.getWidth(); col_num++)
            {
                pxl_x = 0.5 + col_num;
                p.x = pxl_x;
                p.y = pxl_y;

                cout << p << " ";
                
                
                counter++;
            }

            cout << endl;
        }

        cout << counter << endl;
        return vector<double> {0.0,0.0,0.0};
    }

    bool sphereDetection(Point p)
    //We only need to check if there's a point on the sphere at the x,y coordinates of our pixel's center
    //Check if x,y point lies within cross section of sphere with sphere radius
        //Check if distance from point in x,y to center of sphere is less than or equal to radius
    //To get point on sphere, use pythagorean theorem: r^2 = x^2 + y^2 + z^2, solve for z
        //account for sphere position r^2 = (x-h)^2 + (y-k)^2 + (z-l)^2
        //Should have 2 answers since it should intersect in two places on sphere, use one closest to viewing plane
    {





        return 0;
    }






};



class PrintGraphics
{
private:
    Display d;
    //vector<vector<double>> raw_input;
    const vector<string> chars = { " ", ".", "-", "=", "o", "O", "0", "@" };
    int chars_size = chars.size();

public:
    PrintGraphics(Display d):
    d(d)
    //raw_input(raw_input)
    {}

    //.-=oO0Q@

    
    //https://stackoverflow.com/questions/19719252/iterating-through-a-2d-vector-row
    //Double for-loop is bad, but using it for now
    //Also hard-coding in character positions, need to clean that up
    //Also using large if-else statements, need to find better way for that -> map?
    void iterateInput(vector<vector<double>> raw_input) const
    {

        for (auto& row : raw_input)
        {
            for (auto& col : row)
            {

                
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
                    cout << col << " BROKEN, value less than 0!";
                }
                
            }

            cout << endl;
        }
    }

    //         
    //        00Q@Q00
    //     oO000QQQ000Oo
    //    ooOOO00Q00OOOoo
    //    ooOOO00000OOOoo
    //     oooOO000OOooo
    //       .--==--.      
    //           
    //

};



/*
        std::vector< std::vector<int> >::const_iterator row; 
        std::vector<int>::const_iterator col; 

        for (row = vec.begin(); row != vec.end(); ++row)
        { 
            for (col = row->begin(); col != row->end(); ++col)
            { 
                std::cout << *col; 
            } 
    } 
    */


class VectorOps
{
public:

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
        double sqrt_inner, magnitude = 0;
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
    

    void magnitude()
    {

    }

    void normalize()
    {

    }

};


//TODO: normal vectors, create ray vectors, ray collision detection, templatize



int main()
{

    vector<vector<double>> raw_input = { {0.2, 0.0, 0.5, 1.0}, 
                                         {0.51, 0.75, 0.8, 0.6},
                                         {0.49, 0.35, 0.45, 1.0},
                                         {0.72, 0.15, 0.5, 1.0},
                                        }; 
    
    Display d(10,25);
    Sphere s(20.0);
    LightSource l_src;

    PrintGraphics p(d);
    p.iterateInput(raw_input);

    RayCast rc(d, l_src, s);
    rc.cast();

    return 0;
}