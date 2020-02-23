#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>

class Matrix {
public:
    Matrix();
    Matrix(int n, int m);
    ~Matrix() = default;

    std::vector<int> operator[](int i) const;
    Matrix &operator=(const Matrix &m);

    void matr_load(std::string file_name);
    void matr_print();
    void matr_add(Matrix const& m);
    void matr_mul(Matrix const& m);
    void matr_elem(int i, int j);
private:
    int rows = 0;
    int cols = 0;
    std::vector<std::vector<int>> matr;
};

class Matrix_Exception: public std::exception {
public:
    Matrix_Exception(std::string _message);
    virtual const std::string what();
private:
    std::string message;
};
