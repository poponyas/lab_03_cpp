#include "Pentagon.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Pentagon::Pentagon(double x, double y, double s)
    : center_x(x), center_y(y), side(s) {}

std::pair<double, double> Pentagon::getCenter() const
{
    return {center_x, center_y};
}

double Pentagon::area() const
{
    return (5.0 * side * side) / (4.0 * std::tan(M_PI / 5.0));
}

void Pentagon::printVertices(std::ostream &os) const
{
    double R = side / (2 * std::sin(M_PI / 5.0));

    for (int i = 0; i < 5; ++i)
    {
        double angle = 2 * M_PI * i / 5 - M_PI / 2;
        double vertex_x = center_x + R * std::cos(angle);
        double vertex_y = center_y + R * std::sin(angle);
        os << "(" << vertex_x << ", " << vertex_y << ")";
        if (i < 4)
            os << " ";
    }
}

void Pentagon::readFromStream(std::istream &is)
{
    is >> center_x >> center_y >> side;
}

Pentagon::operator double() const
{
    return area();
}

Pentagon &Pentagon::operator=(const Figure &other)
{
    const Pentagon *otherPentagon = dynamic_cast<const Pentagon *>(&other);
    if (otherPentagon != nullptr)
    {
        center_x = otherPentagon->center_x;
        center_y = otherPentagon->center_y;
        side = otherPentagon->side;
    }
    return *this;
}

Pentagon &Pentagon::operator=(Figure &&other)
{
    Pentagon *otherPentagon = dynamic_cast<Pentagon *>(&other);
    if (otherPentagon != nullptr)
    {
        center_x = otherPentagon->center_x;
        center_y = otherPentagon->center_y;
        side = otherPentagon->side;

        otherPentagon->center_x = 0;
        otherPentagon->center_y = 0;
        otherPentagon->side = 0;
    }
    return *this;
}

bool Pentagon::operator==(const Figure &other) const
{
    const Pentagon *otherPentagon = dynamic_cast<const Pentagon *>(&other);
    if (otherPentagon == nullptr)
    {
        return false;
    }
    return center_x == otherPentagon->center_x &&
           center_y == otherPentagon->center_y &&
           side == otherPentagon->side;
}