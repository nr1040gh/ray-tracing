#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <vector>
#include "display.hpp"
#include "print_graphics.hpp"
using namespace std;


PrintGraphics::PrintGraphics(Display d):
    d(d)
    {}
    
    
void PrintGraphics::iterateInput(vector< vector<double> > raw_input) const
//https://stackoverflow.com/questions/19719252/iterating-through-a-2d-vector-row
//Double for-loop is bad, but using it for now
//Also hard-coding in character positions, need to clean that up
//Also using large if-else statements, need to find better way for that -> map?
//Keep input as nested vector or not? Which is more efficient
//Frame rate is also hard-coded!!! Should not clear screen if not animated!!!
{
    string outstring = "";
    for (auto& row : raw_input)
    {
        for (auto& col : row)
        {
            
            if ( (col <= 1.0) && (col >= 0.875) )
            {
                outstring += chars[7];
            }
            else if ( (col < 0.875) && (col >= 0.75) )
            {
                outstring += chars[6];
            }
            else if ( (col < 0.75) && (col >= 0.625) )
            {
                outstring += chars[5];
            }
            else if ( (col < 0.625) && (col >= 0.5) )
            {
                outstring += chars[4];
            }
            else if ( (col < 0.5) && (col >= 0.375) )
            {
                outstring += chars[3];
            }
            else if ( (col < 0.375) && (col >= 0.25) )
            {
                outstring += chars[2];
            }
            else if ( (col < 0.25) && (col >= 0.125) )
            {
                outstring += chars[1];
            }
            else if ( (col < 0.125) && (col >= 0.0) )
            {
                outstring += chars[0];
            }
            
            //If cosine similarity result is less than 0, treat as 0 for now
            else
            {
                outstring += chars[0];
            }
            
        }
      
        outstring += "\n";

    }

    //Created as one big string so we can clear terminal and print all at once
    cout << outstring;
    
    //https://stackoverflow.com/questions/8486181/how-to-make-a-loading-animation-in-console-application-written-in-c
    //https://www.softwaretestinghelp.com/cpp-sleep/
    //https://mathbits.com/MathBits/CompSci/Introduction/clear.htm
    //framerate = 60fps, clear after printing
    Sleep((1.0/60.0)*1000.0);
    cout << flush;
    system ("CLS");
}