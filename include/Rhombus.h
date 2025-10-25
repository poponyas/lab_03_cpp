#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

class Rhombus : public Figure
{
private:
    double center_x, center_y;
    double diagonal1, diagonal2;

public:
    Rhombus(double x = 0, double y = 0, double d1 = 2, double d2 = 1);

    std::pair<double, double> getCenter() const override;
    double area() const override;
    void printVertices(std::ostream &os) const override;
    void readFromStream(std::istream &is) override;

    operator double() const override;

    Rhombus &operator=(const Figure &other) override;
    Rhombus &operator=(Figure &&other) override;
    bool operator==(const Figure &other) const override;
};

#endif