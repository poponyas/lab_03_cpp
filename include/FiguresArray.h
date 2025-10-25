#ifndef FIGURESARRAY_H
#define FIGURESARRAY_H

#include "Figure.h"

class FiguresArray
{
private:
    Figure **figures;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity);

public:
    FiguresArray();
    FiguresArray(const FiguresArray &other);
    FiguresArray(FiguresArray &&other) noexcept;
    ~FiguresArray();

    void addFigure(Figure *figure);
    void removeFigure(size_t index);
    double totalArea() const;
    void printAllInfo() const;
    size_t getSize() const;

    FiguresArray &operator=(const FiguresArray &other);
    FiguresArray &operator=(FiguresArray &&other) noexcept;
};

#endif