#ifndef VECTOR_OPS_HPP
#define VECTOR_OPS_HPP
#include <vector>
#include "point.hpp"

//http://www.math.uaa.alaska.edu/~afkjm/csce211/handouts/SeparateCompilation.pdf
//http://www.cppforschool.com/tutorial/separate-header-and-implementation-files.html
namespace vector_ops
{

//Templatize these below for any general container, not just vectors?

/**
 * @brief Get dot product between two vectors. Vectors should be same length
 * 
 * @param v1        vector1 same length as vector2
 * @param v2        vector2 same length as vector1
 * @return double   Result of the dot product operation
 */
double dotProd(std::vector<double> v1, std::vector<double> v2);


/**
 * @brief Get unit vector of a vector
 * 
 * @param v1                     vector1
 * @return std::vector<double>   New vector object representing unit vector
 */
std::vector<double> unitVec(std::vector<double> v1);


/**
 * @brief Get cosine similarity between 2 vectors. Result is between -1 and 1, inclusive
 * 
 * @param v1        vector1 same length as vector2
 * @param v2        vector2 same length as vector1
 * @return double   Cosine similarity result [-1,1]
 */
double cosSimilarity(std::vector<double> v1, std::vector<double> v2);


/**
 * @brief Get vector object representing vector from point 1 to point 2. 
 * 
 * @param p1                    Point object representing "starting" point. Same dimensions as p2
 * @param p2                    Point object representing "ending" point. Same dimensions as p1
 * @return std::vector<double>  Vector object representing the vector from point 1 to point 2
 */
std::vector<double> getVector(Point p1, Point p2);


}

#endif