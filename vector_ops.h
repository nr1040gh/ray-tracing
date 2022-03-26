
//http://www.math.uaa.alaska.edu/~afkjm/csce211/handouts/SeparateCompilation.pdf
//http://www.cppforschool.com/tutorial/separate-header-and-implementation-files.html
namespace vector_ops
{
    double dotProd(vector<double> v1, vector<double> v2);
    //So far assumes v1 is same dimensions as v2
    //Can template this for any general container


    vector<double> unitVec(vector<double> v1);


    double cosSimilarity(vector<double> v1, vector<double> v2);
    
    
    vector<double> getVector(Point p1, Point p2);

    void magnitude();

    void normalize();

}