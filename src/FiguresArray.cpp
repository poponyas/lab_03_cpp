#include "FiguresArray.h"
#include <iostream>
#include <stdexcept>

FiguresArray::FiguresArray() : figures(nullptr), size(0), capacity(0) {}

FiguresArray::FiguresArray(const FiguresArray &other) : size(other.size), capacity(other.capacity)
{
    figures = new Figure *[capacity];
    for (size_t i = 0; i < size; ++i)
    {
        figures[i] = other.figures[i];
    }
}

FiguresArray::FiguresArray(FiguresArray &&other) noexcept
    : figures(other.figures), size(other.size), capacity(other.capacity)
{
    other.figures = nullptr;
    other.size = 0;
    other.capacity = 0;
}

FiguresArray::~FiguresArray()
{
    for (size_t i = 0; i < size; ++i)
    {
        delete figures[i];
    }
    delete[] figures;
}

void FiguresArray::resize(size_t new_capacity)
{
    Figure **new_figures = new Figure *[new_capacity];
    for (size_t i = 0; i < size; ++i)
    {
        new_figures[i] = figures[i];
    }
    delete[] figures;
    figures = new_figures;
    capacity = new_capacity;
}

void FiguresArray::addFigure(Figure *figure)
{
    if (size >= capacity)
    {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    figures[size++] = figure;
}

void FiguresArray::removeFigure(size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    delete figures[index];
    for (size_t i = index; i < size - 1; ++i)
    {
        figures[i] = figures[i + 1];
    }
    --size;
}

double FiguresArray::totalArea() const
{
    double total = 0.0;
    for (size_t i = 0; i < size; ++i)
    {
        total += figures[i]->area();
    }
    return total;
}

void FiguresArray::printAllInfo() const
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "Figure " << i + 1 << ":\n";
        std::cout << "Vertices: " << *figures[i] << "\n";
        auto center = figures[i]->getCenter();
        std::cout << "Geometric Center: (" << center.first << ", " << center.second << ")\n";
        std::cout << "Area: " << figures[i]->area() << "\n\n";
    }
}

size_t FiguresArray::getSize() const
{
    return size;
}

FiguresArray &FiguresArray::operator=(const FiguresArray &other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < size; ++i)
        {
            delete figures[i];
        }
        delete[] figures;

        size = other.size;
        capacity = other.capacity;
        figures = new Figure *[capacity];
        for (size_t i = 0; i < size; ++i)
        {
            figures[i] = other.figures[i];
        }
    }
    return *this;
}

FiguresArray &FiguresArray::operator=(FiguresArray &&other) noexcept
{
    if (this != &other)
    {
        for (size_t i = 0; i < size; ++i)
        {
            delete figures[i];
        }
        delete[] figures;

        figures = other.figures;
        size = other.size;
        capacity = other.capacity;

        other.figures = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}