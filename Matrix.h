#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

typedef double ElementType;
typedef double *ElementTypePtr;

template <class T>
class Array {
        unsigned m_size;
        T *m_matrix;
    public:
        Array(unsigned size);
        ~Array();
        Array operator-(Array &);
        T& operator[](const unsigned &index);
        void print() const;
        unsigned getSize() const;
};

template <class T>
class Matrix {
        unsigned m_rowSize;
        unsigned m_colSize;
        T **m_matrix;
    public:
        Matrix(unsigned rowSize, unsigned colSize);
        ~Matrix();
        Matrix<T> operator*(Matrix<T> &);
        Array<T> operator*(Array<T> &);
        T *& operator[](const unsigned &);
        void print() const;
        unsigned getRows() const;
        unsigned getCols() const;
};


#endif // MATRIX_H
