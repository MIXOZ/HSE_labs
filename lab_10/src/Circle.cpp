#include "Figure.hpp"
#include "Circle.hpp"

#include <cstring>
#include <iostream>

Circle::Circle(int id, int x, int y, int radius, const char* label):Figure(id, x, y) {
    radius_ = radius;
    label_ = new char [std::strlen(label) + 1];
    std::strcpy (label_, label);
}


Circle::~Circle(){
    delete[] label_;
}


bool Circle::is_inside(int x, int y) const {
    return (x_ - radius_ <= x) && (x_ + radius_ >= x) && (y_ - radius_ <= y) && (y_ + radius_ >= y);
}


void Circle::print() const {
    std::cout << "Circle " << id_ << ": x = " << x_ << " y = " << y_;
    std::cout << " radius = " << radius_ << " label = " << label_ << "\n";
}


void Circle::zoom(int factor){
    radius_ *= factor;
}