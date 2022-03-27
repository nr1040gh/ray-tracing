#include <iostream>
#include <string>
#include <vector>
#include "display.hpp"
#include "print_graphics.hpp"
using namespace std;


PrintGraphics::PrintGraphics(Display d):
    d(d)
    //raw_input(raw_input)
    {}
    
    
void PrintGraphics::iterateInput(vector< vector<double> > raw_input) const
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