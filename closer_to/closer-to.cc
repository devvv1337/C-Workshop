#include "closer-to.hh"

CloserTo::CloserTo(int i)
    : i_(i)
{}

bool CloserTo::operator()(const int& a, const int& b) const
{
    int distToA;
    int distToB;
    if (a - i_ < 0)
        distToA = i_ - a;
    else
        distToA = a - i_;
    if (b - i_ < 0)
        distToB = i_ - b;
    else
        distToB = b - i_;

    if (a == b)
        return a < b;
    if (distToA == distToB)
    {
        return a < b;
    }
    else
    {
        return distToA < distToB;
    }
}