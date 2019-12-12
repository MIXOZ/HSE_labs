#pragma once

#include "Figure.hpp"


class Circle : public Figure {
public:
    Circle(int id, int x, int y, int radius, const char* label);

    virtual ~Circle();

    virtual bool is_inside(int x, int y) const;

    virtual void print() const;

    void zoom(int factor);

protected:
    int radius_;
    char* label_;
};
