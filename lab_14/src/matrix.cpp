#include <matrix.h>

//==================Constructors===================

Matrix::Matrix() {
    rows = 0;
    cols = 0;
}

Matrix::Matrix(int n, int m) : rows(n), cols(m) {
    matr.resize(rows);
    for (int i = 0; i < rows; i++) {
        matr[i].resize(cols);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matr[i][j] = 0;
        }
    }
}

//==================Operators=====================

Matrix& Matrix::operator=(const Matrix &m) {
    rows = m.rows;
    cols = m.cols;
    matr.resize(rows);
    for (int i = 0; i < rows; i++) {
        matr[i].resize(cols);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matr[i][j] = m.matr[i][j];
        }
    }
    return *this;
}

//=================Functions==================

void Matrix::matr_load(std::string file_name) {
	std::ifstream in(file_name);
    if (!in.is_open()) {
        throw Matrix_Exception("LOAD: unable to open file.");
    }
    int _rows = 1;
    int _cols = 1;
	in >> _rows;
    in >> _cols;
    Matrix res = Matrix(_rows, _cols);
	for (int i = 0; i < _rows; i++) {
    	for (int j = 0; j < _cols; j++) {
        	in >> res.matr[i][j];
        }
    }
    in.close();
    if (!in.good()) {
        throw Matrix_Exception("LOAD: invalid file format.");
    }
    *this = res;
}

void Matrix::matr_print() {
    for (int i = 0 ; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void Matrix::matr_add(Matrix const& m) {
    if ((rows != m.rows) || (cols != m.cols)) {
        throw Matrix_Exception("ADD: dimensions do not match.");
    }
    for (int i = 0 ; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matr[i][j] += m.matr[i][j];   
        }
    }
}

void Matrix::matr_mul(Matrix const& m) {
    if (cols != m.rows) {
        throw Matrix_Exception("MUL: #arg1.columns != #arg2.rows.");
    }
    Matrix res = Matrix(rows, m.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            long long curr = 0;
            for (int k = 0; k < cols; k++)
                curr = curr + (matr[i][k] * m.matr[k][j]);
            res.matr[i][j] = curr;
        }
    }
    *this = res;
}

void Matrix::matr_elem(int i, int j) {
    if (i >= rows || j >= cols || i < 0 || j < 0) {
        throw Matrix_Exception("ACCESS: bad index.");
    }
    std::cout << matr[i][j] << '\n';
}

//======================Exception======================

Matrix_Exception::Matrix_Exception(std::string _message){
    message = _message;
}

const std::string Matrix_Exception::what() {
    return message;
}
