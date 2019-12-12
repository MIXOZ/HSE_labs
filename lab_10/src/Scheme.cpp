#include "Scheme.hpp"
#include "Figure.hpp"

Scheme::Scheme(int capacity) {
    figures_ = new Figure*[capacity];
    size_ = 0;
    capacity_ = capacity;
    for (int i = 0; i < capacity; ++i)
        figures_[i] = nullptr;
}


Scheme::~Scheme() {
    for (int i = 0; i < capacity_; ++i)
        delete figures_[i];
    delete[] figures_;
}


void Scheme::push_back_figure(Figure* fg) {
    figures_[size_] = fg;
    size_++;
}


void Scheme::remove_figure(int id) {
    int i = 0;
    while (figures_[i]->return_id() != id && i <= size_) {
        ++i;
    }
    delete figures_[i];
    while (figures_[i] != nullptr && i <= size_ - 1) {
        figures_[i] = figures_[i + 1];
        ++i;
    }
    figures_[size_] = nullptr;
    size_ --;
}

void Scheme::print_all_figures() {
    for(int i = 0; i < size_; ++i)
        figures_[i]->print();
}

void Scheme::zoom_figure(int id, int factor) {
    int i = 0;
    while (figures_[i]->return_id() != id && i <= size_) {
        ++i;
    }
    figures_[i]->zoom(factor);
}

Figure* Scheme::is_inside_figure(int x, int y) {
    int i;
    for (i = 0; i <= size_; ++i)
        if (figures_[i]->is_inside(x, y)) break;
    return figures_[i];
} // если внутри нескольких фигур, то возвращается любая из них

void Scheme::move(int id, int new_x, int new_y) {
    int i = 0;
    while (figures_[i]->return_id() != id && i <= size_) {
        ++i;
    }
    figures_[i]->move(new_x, new_y);
}