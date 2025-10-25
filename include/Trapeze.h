#ifndef TRAPEZE_H
#define TRAPEZE_H

#include "Figure.h"

class Trapeze : public Figure
{
private:
    double center_x, center_y;
    double base1, base2;
    double height;

public:
    Trapeze(double x = 0, double y = 0, double b1 = 2, double b2 = 1, double h = 1);

    std::pair<double, double> getCenter() const override;
    double area() const override;
    void printVertices(std::ostream &os) const override;
    void readFromStream(std::istream &is) override;

    operator double() const override;

    Trapeze &operator=(const Figure &other) override;
    Trapeze &operator=(Figure &&other) override;
    bool operator==(const Figure &other) const override;
};

#endif