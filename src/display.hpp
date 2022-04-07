#ifndef DISPLAY_HPP
#define DISPLAY_HPP

/**
 * @brief Class showing height and width (in number of characters) for viewing screen (terminal display)
 * Will use left handed 3d coord system: https://www.povray.org/documentation/3.7.0/t2_2.html (pos y up, pos x right, pos z out)
 * Viewing plane (display) will be z = 0, stretching in the positive x-y plane
 */
class Display
{
private:
    const int height;               //height of the viewing screen (terminal)
    const int width;                //width of the viewing screen (terminal)
    double viewing_distance = 100;  //deprecated for now, needed for perspective
    
public:

    //Initialize with height and width of viewing screen
    Display(const int height, const int width);
    
    const int getHeight() const;
    const int getWidth() const;
    
};


#endif