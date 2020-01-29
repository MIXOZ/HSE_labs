#ifndef LAB11_BIN_MANIP_H_INCLUDED
#define LAB11_BIN_MANIP_H_INCLUDED

#include <iosfwd>
#include <string>
#include <cassert>


class write_le_int32 {
public:
    explicit write_le_int32(int32_t data) : _data(data) {};
    std::ostream &operator()(std::ostream &out) const;
private:
    int32_t _data;
};

std::ostream &operator <<(std::ostream &out, write_le_int32 const &data);


class read_le_int32 {
public:
    explicit read_le_int32(int32_t &data);
    std::istream &operator()(std::istream &in);
private:
    int32_t *_data;
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
    explicit write_str(std::string data) : _data(data) {};
    std::ostream &operator()(std::ostream &out) const;
private:
    std::string _data;
};

std::ostream &operator <<(std::ostream &out, write_str const &data);


class read_str {
public:
    explicit read_str(std::string &data);
    std::istream &operator()(std::istream &in);
private:
    std::string *_data;
};

std::istream &operator >>(std::istream &in, read_str data);


#endif