#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include <iostream>
#include <cstddef>
#include <cstring>
#include <utility>
#include <cassert>
#include <exception>

namespace my_vector {

template<typename T>
class my_vector {
public:
    explicit my_vector(const std::size_t n);
    my_vector();
    my_vector(const my_vector &other);
    my_vector(my_vector &&other) ;
    my_vector &operator=(my_vector &&other) ;
    my_vector &operator=(const my_vector &other);
    ~my_vector();

    std::size_t size()const noexcept;
    std::size_t capacity()const noexcept;
    bool empty()const noexcept;

    void resize(std::size_t n);
    void reserve(std::size_t n);

    T& operator[](std::size_t index)const;
    T& operator[](std::size_t index);

    void push_back(const T& t);
    void push_back(T&& t);
    void pop_back();
    void clear();

    bool operator==(const my_vector& other) const;
	bool operator!=(const my_vector& other) const;

	size_t capacity();
private:
    size_t _capacity;
    size_t _size;
    T* _array;
};

}

#include "my_vector_impl.h"

#endif  // MY_VECTOR_H_