#ifndef DISPLAY_HPP
#define DISPLAY_HPP


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
    Display(const int height, const int width);
    
    const int getHeight() const;
    
    const int getWidth() const;
};


#endif