#ifndef LAB11_BIN_MANIP_H_INCLUDED
#define LAB11_BIN_MANIP_H_INCLUDED

#include <iosfwd>
#include <cassert>


class write_le_int32 {
public:
    explicit write_le_int32(int data) : _data(data) {};
    std::ostream &operator()(std::ostream &out) const;
private:
    int _data;
};

std::ostream &operator <<(std::ostream &out, write_le_int32 const &data);


class read_le_int32 {
public:
    explicit read_le_int32(int &data);
    std::istream &operator()(std::istream &in);
private:
    int *_data;
};

std::istream &operator >>(std::istream &in, read_le_int32 data);


class write_bool {
public:
    explicit write_bool(bool data) : _data(data) {};
    std::ostream &operator()(std::ostream &out) const;
private:
    bool _data;
};

std::ostream &operator <<(std::ostream &out, write_bool const &data);


class read_bool {
public:
    explicit read_bool(bool &data);
    std::istream &operator()(std::istream &in);
private:
    bool *_data;
};

std::istream &operator >>(std::istream &in, read_bool data);

class write_str {
public:
    explicit write_str(char* data) : _data(data) {};
    std::ostream &operator()(std::ostream &out) const;
private:
    char *_data;
};

std::ostream &operator <<(std::ostream &out, write_str const &data);


class read_str {
public:
    explicit read_str(char* data) : _data(data) {};
    std::istream &operator()(std::istream &in);
private:
    char *_data;
};

std::istream &operator >>(std::istream &in, read_str data);


#endif