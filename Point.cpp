struct Point
{
    double x=0.0, y=0.0, z=0.0;
    
};

ostream& operator << (ostream& os, Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}