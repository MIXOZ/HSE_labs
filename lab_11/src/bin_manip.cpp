#include "bin_manip.hpp"
#include <iostream>
#include <cassert>

std::ostream& write_le_int32::operator()(std::ostream &out) const {
    out.write((char *)(&_data), sizeof(int));
    return out;
}


std::ostream &operator <<(std::ostream &out, write_le_int32 const &data) {
    return data(out);
}


read_le_int32::read_le_int32(int &data) {
    _data = &data;
}


std::istream& read_le_int32::operator()(std::istream &in) {
    in.read((char *)_data, sizeof(int));
    return in;
}


std::istream &operator >>(std::istream &in, read_le_int32 data) {
    return data(in);
}


std::ostream& write_bool::operator()(std::ostream &out) const {
    return out << (char)_data;
}


std::ostream &operator <<(std::ostream &out, write_bool const &data) {
    return data(out);
}


read_bool::read_bool(bool &data) {
    _data = &data;
}


std::istream& read_bool::operator()(std::istream &in) {
    char buffer;
    in >> buffer;
    *_data = (buffer == 1);
    return in;
}


std::istream &operator >>(std::istream &in, read_bool data) {
    return data(in);
}


std::ostream& write_str::operator()(std::ostream &out) const {
    out << _data << '\0';
    return out;
}


std::ostream &operator <<(std::ostream &out, write_str const &data) {
    return data(out);
}


std::istream& read_str::operator()(std::istream &in) {
    char buffer;
    in >> buffer;
    int i = 0;
    while (buffer != '\0') {
        _data[i++] = buffer;
        in >> buffer;
        assert(i < 100);
    }
    _data[i] = buffer;
    return in;
}


std::istream &operator >>(std::istream &in, read_str data) {
    return data(in);
}