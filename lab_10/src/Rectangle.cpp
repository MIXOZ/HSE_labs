#include "Figure.hpp"
#include "Rectangle.hpp"

#include <iostream>


Rectangle::Rectangle(int id, int x, int y, int width, int height):Figure(id, x, y) {
    width_ = width;
    height_ = height;
}


bool Rectangle::is_inside(int x, int y) const {
    return (x_ - width_ / 2 <= x) && (x_ + width_ / 2 >= x) && (y_ - height_ / 2 <= y) && (y_ + height_ / 2 >= y);
}


void Rectangle::print() const {
    std::cout << "Rectangle " << id_ << ": x = " << x_ << " y = " << y_;
    std::cout << " width = " << width_ << " height = " << height_ << "\n";
}


void Rectangle::zoom(int factor) {
    width_ *= factor;
    height_ *= factor;
}