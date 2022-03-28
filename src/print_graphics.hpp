#ifndef PRINT_GRAPHICS_HPP
#define PRINT_GRAPHICS_HPP

#include <string>
#include <vector>
#include "display.hpp"


class PrintGraphics
{
private:
    Display d;
    const std::vector<std::string> chars{ "  ", "..", "--", "==", "oo", "OO", "QQ", "00" }; //.-=oO0Q0
    
public:
    PrintGraphics(Display d);
    
    
    void iterateInput(std::vector< std::vector<double> > raw_input) const;
    
};


#endif