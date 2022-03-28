#include "display.hpp"


Display::Display(const int height, const int width)
    : height(height)
    , width(width)
    , xmax(width)
    , ymax(height)
    {}
    

const int Display::getHeight() const
{
    return height;
}


const int Display::getWidth() const
{
    return width;
}
