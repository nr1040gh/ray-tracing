#ifndef VECTOR_OPS_HPP
#define VECTOR_OPS_HPP
#include <vector>
#include "point.hpp"

//http://www.math.uaa.alaska.edu/~afkjm/csce211/handouts/SeparateCompilation.pdf
//http://www.cppforschool.com/tutorial/separate-header-and-implementation-files.html
namespace vector_ops
{
    double dotProd(std::vector<double> v1, std::vector<double> v2);
    //So far assumes v1 is same dimensions as v2
    //Can template this for any general container


    std::vector<double> unitVec(std::vector<double> v1);


    double cosSimilarity(std::vector<double> v1, std::vector<double> v2);
    
    
    std::vector<double> getVector(Point p1, Point p2);

    void magnitude();

    void normalize();

}

#endif