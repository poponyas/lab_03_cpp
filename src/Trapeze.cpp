#include "../include/Trapeze.h"
#include <iostream>
#include <cmath>

Trapeze::Trapeze(double x, double y, double b1, double b2, double h)
    : center_x(x), center_y(y), base1(b1), base2(b2), height(h) {}

std::pair<double, double> Trapeze::getCenter() const
{
    return {center_x, center_y};
}

double Trapeze::area() const
{
    return (base1 + base2) * height / 2.0;
}

void Trapeze::printVertices(std::ostream &os) const
{
    double half_h = height / 2.0;
    double offset1 = base1 / 2.0;
    double offset2 = base2 / 2.0;

    os << "(" << center_x - offset2 << ", " << center_y - half_h << ") "
       << "(" << center_x + offset2 << ", " << center_y - half_h << ") "
       << "(" << center_x + offset1 << ", " << center_y + half_h << ") "
       << "(" << center_x - offset1 << ", " << center_y + half_h << ")";
}

void Trapeze::readFromStream(std::istream &is)
{
    is >> center_x >> center_y >> base1 >> base2 >> height;
}

Trapeze::operator double() const
{
    return area();
}

Trapeze &Trapeze::operator=(const Figure &other)
{
    const Trapeze *otherTrapeze = dynamic_cast<const Trapeze *>(&other);
    if (otherTrapeze != nullptr)
    {
        center_x = otherTrapeze->center_x;
        center_y = otherTrapeze->center_y;
        base1 = otherTrapeze->base1;
        base2 = otherTrapeze->base2;
        height = otherTrapeze->height;
    }
    return *this;
}

Trapeze &Trapeze::operator=(Figure &&other)
{
    Trapeze *otherTrapeze = dynamic_cast<Trapeze *>(&other);
    if (otherTrapeze != nullptr)
    {
        center_x = otherTrapeze->center_x;
        center_y = otherTrapeze->center_y;
        base1 = otherTrapeze->base1;
        base2 = otherTrapeze->base2;
        height = otherTrapeze->height;

        otherTrapeze->center_x = 0;
        otherTrapeze->center_y = 0;
        otherTrapeze->base1 = 0;
        otherTrapeze->base2 = 0;
        otherTrapeze->height = 0;
    }
    return *this;
}

bool Trapeze::operator==(const Figure &other) const
{
    const Trapeze *otherTrapeze = dynamic_cast<const Trapeze *>(&other);
    if (otherTrapeze == nullptr)
    {
        return false;
    }
    return center_x == otherTrapeze->center_x &&
           center_y == otherTrapeze->center_y &&
           base1 == otherTrapeze->base1 &&
           base2 == otherTrapeze->base2 &&
           height == otherTrapeze->height;
}