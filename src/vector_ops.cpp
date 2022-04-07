#include <vector>
#include <cmath>
#include "point.hpp"
#include "vector_ops.hpp"

using namespace std;

//TODO: templatize
namespace vector_ops{

//Templatize these below for any general container, not just vectors?

double dotProd(vector<double> v1, vector<double> v2)
{
    //So far assumes v1 is same dimensions as v2

    double result = 0;
    for (int i=0; i < v1.size(); i++)
    {
        result += v1[i] * v2[i];
    }
    
    return result;
}


vector<double> unitVec(vector<double> v1)
//Get magnitude of vector then divide contents of vector by magnitude
{
    
    vector<double> unitVec;
    double sqrt_inner = 0, magnitude = 0;
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
//dot product between 2 unit vectors returns the cosine similarity - value between -1 and 1, inclusive
{
    vector<double> unitVec1 = unitVec(v1);
    vector<double> unitVec2 = unitVec(v2);
    
    double result = dotProd(unitVec1,unitVec2);
    
    return result;
}


vector<double> getVector(Point p1, Point p2)
//Get vector pointing from p1 to p2
//Generalize to not hard-code x,y,z?
{
    vector<double> result{ (p2.x - p1.x), (p2.y - p1.y), (p2.z - p1.z) };
    
    return result;
}



}
