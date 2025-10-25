#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

class Pentagon : public Figure
{
private:
    double center_x, center_y;
    double side;

public:
    Pentagon(double x = 0, double y = 0, double s = 1);

    std::pair<double, double> getCenter() const override;
    double area() const override;
    void printVertices(std::ostream &os) const override;
    void readFromStream(std::istream &is) override;

    operator double() const override;

    Pentagon &operator=(const Figure &other) override;
    Pentagon &operator=(Figure &&other) override;
    bool operator==(const Figure &other) const override;
};

#endif