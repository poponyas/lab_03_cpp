#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>

class Figure
{
public:
    virtual ~Figure() {}

    virtual std::pair<double, double> getCenter() const = 0;
    virtual double area() const = 0;
    virtual void printVertices(std::ostream &os) const = 0;
    virtual void readFromStream(std::istream &is) = 0;

    virtual operator double() const = 0;

    virtual Figure &operator=(const Figure &other) = 0;
    virtual Figure &operator=(Figure &&other) = 0;
    virtual bool operator==(const Figure &other) const = 0;
};

inline std::ostream &operator<<(std::ostream &os, const Figure &fig)
{
    fig.printVertices(os);
    return os;
}

inline std::istream &operator>>(std::istream &is, Figure &fig)
{
    fig.readFromStream(is);
    return is;
}

#endif