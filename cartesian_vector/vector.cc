#include "vector.hh"

Vector& Vector::operator+=(const Vector& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vector& Vector::operator*=(int scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& vect)
{
    return os << '{' << vect.x << ',' << vect.y << '}';
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    return Vector{ lhs.x + rhs.x, lhs.y + rhs.y };
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
    return Vector{ lhs.x - rhs.x, lhs.y - rhs.y };
}

Vector operator*(const Vector& lhs, int scalar)
{
    return Vector{ lhs.x * scalar, lhs.y * scalar };
}

Vector operator*(int scalar, const Vector& rhs)
{
    return rhs * scalar;
}

int operator*(const Vector& lhs, const Vector& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}
