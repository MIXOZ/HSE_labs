#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <cstddef>
#include <stdexcept>

namespace lab_13 {

template<typename T, std::size_t N>
class my_array {
public:
    T& at(std::size_t index) {
        if (index > 0 && index >= N) throw std::out_of_range("exept");
        return _array[index];
    }
    const T& at(std::size_t index) const {
        if (index > 0 && index >= N) throw std::out_of_range("exept");
        return _array[index];
    }

    T& operator[](std::size_t index) {
        return _array[index];
    }
    const T& operator[](std::size_t index) const {
        return _array[index];
    }

    bool empty() const {
        return N == 0;
    }
    size_t size() const {
        return N;
    }

    void fill(const T& value) {
        for (std::size_t i = 0; i < N; i++)
            _array[i] = value;
    }

private:
    T _array[N];
};

template<std::size_t N>
class my_array<bool, N> {
private:
    const std::size_t _capacity = (N + 7) >> 3;
    uint8_t _array[(N + 7) >> 3];

    std::size_t get_block(std::size_t index) const {
        return index >> 3;
    }
    std::size_t get_index(std::size_t index) const {
        return index & 7;
    }

    class _proxy {
    public:
        _proxy(uint8_t* block, std::size_t index) :
                block(block), index(index) {
        }
        _proxy& operator=(_proxy other) {
            return *this = bool(other);
        }
        _proxy& operator=(bool value) {
            *block &= ~(1 << index);
            *block |= ((int)value) << index;
            return *this;
        }
        operator bool() const {
            return bool((*block >> index) & 1);
        }

        uint8_t* block;
        std::size_t index;
    };

public:
    _proxy at(std::size_t index) {
        if (index > 0 && index >= N) throw std::out_of_range("exept");
        return operator[](index);
    }
    bool at(std::size_t index) const {
        if (index > 0 && index >= N) throw std::out_of_range("exept");
        return operator[](index);
    }

    _proxy operator[](std::size_t index) {
        return _proxy(_array + get_block(index), get_index(index));
    }
    bool operator[](std::size_t index) const {
        return (_array[get_block(index)] >> get_index(index)) & 1;
    }

    bool empty() const {
        return N == 0;
    }

    std::size_t size() const {
        return N;
    }

    void fill(const bool& value) {
        for (std::size_t i = 0; i < _capacity; i++)
            _array[i] = (value ? -1 : 0);
    }
};

}  // namespace lab_13

#endif  // MY_ARRAY_H_