#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef unsigned IndexType;

template <class T>
class Array {
        IndexType m_size;
        T *m_matrix;
    public:
        Array(unsigned size);
        ~Array();
        Array operator-(Array &);
        T& operator[](const IndexType &index);
        void print() const;
        IndexType getSize() const;
};

template <class T>
class Matrix {
        IndexType m_rowSize;
        IndexType m_colSize;
        T **m_matrix;
    public:
        Matrix(IndexType rowSize, IndexType colSize, bool fill);
        ~Matrix();
        Matrix<T> operator*(Matrix<T> &);
        Array<T> operator*(Array<T> &);
        T *& operator[](const IndexType &);
        void print() const;
        IndexType getRows() const;
        IndexType getCols() const;
};


#endif // MATRIX_H
