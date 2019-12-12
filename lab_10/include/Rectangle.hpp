#include "Figure.hpp"


class Rectangle : public Figure {
public:
    Rectangle(int id, int x, int y, int width, int height);

    virtual bool is_inside(int x, int y) const;

    virtual void print() const;

    void zoom(int factor);

protected:
    int height_;
    int width_;
};