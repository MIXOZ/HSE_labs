#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <my_vector.h>

namespace my_vector {

template<typename T>
my_vector<T>::my_vector(const std::size_t n) {
    _capacity = 1;
    while (_capacity < n)
        _capacity *= 2;
    _size = n;
    std::size_t i = 0;
    try {
        _array = (T*) new char[_capacity * sizeof(T)];
        for (i = 0; i < _size; i++)
            new (_array + i) T();
    }
    catch (std::exception &e){
        for (std::size_t j = i + 1; j > 0; j--) {
            _array[j - 1].~T();
        }
        delete []_array;
    }
}

template<typename T>
my_vector<T>::my_vector() {
    _size = 0;
    _capacity = 1;
    _array = (T*) new char[_capacity * sizeof(T)];    
}
    
template<typename T>
my_vector<T>::my_vector(const my_vector& other) {
    _capacity = other._capacity;
    _size = other._size;
    std::size_t i = 0;
    try {
        _array = (T*) new char[_capacity * sizeof(T)];
        for (i = 0; i < _size; i++)
            new (_array + i) T();
    }
    catch (std::exception &e){
        for (std::size_t j = i + 1; j > 0; j--) {
            _array[j - 1].~T();
        }
        delete []_array;
    }
    for (std::size_t i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
}
    
template<typename T>
my_vector<T>::my_vector(my_vector &&other)
    :_array(other._array), _capacity(other._capacity), _size(other._size) {
    other._array = nullptr;
    other._size = 0;
    other._capacity = 0;
}
    
template<typename T>
my_vector<T> &my_vector<T>::operator=(my_vector&& other) {
    if (&other == this)
        return *this;
    delete[] _array;
    std::swap(_capacity, other._capacity);
    std::swap(_size, other._size);
    std::swap(_array, other._array);
    other._array = nullptr;
    other._size = 0;
    other._capacity = 0;
    return *this;
}
    
template<typename T>
my_vector<T> &my_vector<T>::operator=(const my_vector& other) {
    my_vector tmp(T(other));
    this = (std::move(tmp));
    return *this;
}
    
template<typename T>
my_vector<T>::~my_vector() {
    for (std::size_t i = 0; i < _size; i++)
        _array[i].~T();
    delete [](char*)_array;
}
    
template<typename T>
size_t my_vector<T>::size() const noexcept {
    return _size;
}
    
template<typename T>
size_t my_vector<T>::capacity() const noexcept {
    return _capacity;
}
    
template<typename T>
bool my_vector<T>::empty() const noexcept {
    return _size == 0;
}
    
template<typename T>
void my_vector<T>::reserve(std::size_t n) {
    if (n <= _capacity)
        return;
    std::size_t new_capacity = _capacity;
    while (new_capacity < n)
        new_capacity *= 2;
    std::size_t i = 0;
    T* new_array;
    try {
        new_array = (T*) new char[new_capacity * sizeof(T)];
        for (i = 0; i < _size; i++)
            new (new_array + i) T(_array[i]);
    }
    catch (std::exception &e){
        for (std::size_t j = i + 1; j > 0; j--) {
            new_array[j - 1].~T();
        }
        delete []new_array;
    }
    std::swap(_array, new_array);
    _capacity = new_capacity;

    for (size_t i = 0; i < _size; i++)
        new_array[i].~T();
    delete [](char*)new_array;
}
    
template<typename T>
void my_vector<T>::resize(size_t n) {
    if (n > _capacity)
        reserve(n);
    std::size_t new_size = _size;
    try {
        while (new_size < n)
            new (_array + new_size++) T();
    }
    catch (std::exception &e){
        for (size_t i = new_size + 1; i > _size; i--) {
            _array[i - 1].~T();
        }
        delete []_array;
    }
    _size = new_size;
}
    
template<typename T>
T& my_vector<T>::operator[](std::size_t index) {
    return *(_array + index);
}
    
template<typename T>
T& my_vector<T>::operator[](std::size_t index)const {
    return *(_array + index); 
}
    
template<typename T>
void my_vector<T>::push_back(const T& t) {
    push_back(T(t));
}
    
template<typename T>
void my_vector<T>::push_back(T&& t) {
    reserve (_size + 1);
    new (_array + _size++) T(std::move(t));
}
    
template<typename T>
void my_vector<T>::pop_back() noexcept {
    if (_size == 0) return;
    _array[--_size].~T();
}
    
template<typename T>
void my_vector<T>::clear() noexcept {
    while (_size)
        _array[--_size].~T();
}
    
template<typename T>
bool my_vector<T>::operator==(const my_vector& other) const {
    if (_capacity != other._capacity || _size != other._size)
        return false;
    for (std::size_t i = 0; i < _size; i++)
        if (_array[i] != other[i])
            return false;
    return true;
}
    
template<typename T>
bool my_vector<T>::operator!=(const my_vector& other) const {
    return !(*this == other);
}

template <class T>
std::ostream& operator<<(std::ostream& out, const my_vector<T>& vec) {
    if (vec.empty()) return out;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        out << vec[i] << " ";
    }
    return out << vec[vec.size() - 1];
}

template <class T>
size_t my_vector<T>::capacity() {
    return _capacity;
}

}
#endif