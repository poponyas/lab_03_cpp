#include "../include/Rhombus.h"
#include <iostream>
#include <cmath>

Rhombus::Rhombus(double x, double y, double d1, double d2)
    : center_x(x), center_y(y), diagonal1(d1), diagonal2(d2) {}

std::pair<double, double> Rhombus::getCenter() const
{
    return {center_x, center_y};
}

double Rhombus::area() const
{
    return (diagonal1 * diagonal2) / 2.0;
}

void Rhombus::printVertices(std::ostream &os) const
{
    double half_d1 = diagonal1 / 2.0;
    double half_d2 = diagonal2 / 2.0;

    os << "(" << center_x << ", " << center_y + half_d2 << ") "
       << "(" << center_x + half_d1 << ", " << center_y << ") "
       << "(" << center_x << ", " << center_y - half_d2 << ") "
       << "(" << center_x - half_d1 << ", " << center_y << ")";
}

void Rhombus::readFromStream(std::istream &is)
{
    is >> center_x >> center_y >> diagonal1 >> diagonal2;
}

Rhombus::operator double() const
{
    return area();
}

Rhombus &Rhombus::operator=(const Figure &other)
{
    const Rhombus *otherRhombus = dynamic_cast<const Rhombus *>(&other);
    if (otherRhombus != nullptr)
    {
        center_x = otherRhombus->center_x;
        center_y = otherRhombus->center_y;
        diagonal1 = otherRhombus->diagonal1;
        diagonal2 = otherRhombus->diagonal2;
    }
    return *this;
}

Rhombus &Rhombus::operator=(Figure &&other)
{
    Rhombus *otherRhombus = dynamic_cast<Rhombus *>(&other);
    if (otherRhombus != nullptr)
    {
        center_x = otherRhombus->center_x;
        center_y = otherRhombus->center_y;
        diagonal1 = otherRhombus->diagonal1;
        diagonal2 = otherRhombus->diagonal2;

        otherRhombus->center_x = 0;
        otherRhombus->center_y = 0;
        otherRhombus->diagonal1 = 0;
        otherRhombus->diagonal2 = 0;
    }
    return *this;
}

bool Rhombus::operator==(const Figure &other) const
{
    const Rhombus *otherRhombus = dynamic_cast<const Rhombus *>(&other);
    if (otherRhombus == nullptr)
    {
        return false;
    }
    return center_x == otherRhombus->center_x &&
           center_y == otherRhombus->center_y &&
           diagonal1 == otherRhombus->diagonal1 &&
           diagonal2 == otherRhombus->diagonal2;
}