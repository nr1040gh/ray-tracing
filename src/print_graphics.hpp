#ifndef PRINT_GRAPHICS_HPP
#define PRINT_GRAPHICS_HPP

#include <string>
#include <vector>
#include "display.hpp"


/**
 * A class for displaying results of ray-cast on terminal
 */
class PrintGraphics
{
private:

    Display d;  //Viewing screen (terminal display)

    //Characters used for displaying brightness results ->  .-=oO0Q0, in increasing intensity.
    //Characters are doubled due to terminal siplay character width being about half as big as height -> egg shape if left as one character
    const std::vector<std::string> chars{ "  ", "..", "--", "==", "oo", "OO", "QQ", "00" }; 
    
public:

    //initialize with viewing screen
    PrintGraphics(Display d);
    
    
    /**
     * @brief Goes through the results and prints the character on the screen for each pixel's result
     * Clears screen after 1/60 of a second to allow for animating!!!! - This should be changed to only clear if animated!!!!
     * 
     * @param raw_input Container of containers. Top container represents top row of "pixels" on terminal display and their cosine similarity results. Works way down so pixels are displayed correctly.
     */
    void iterateInput(std::vector< std::vector<double> > raw_input) const;
    
};


#endif