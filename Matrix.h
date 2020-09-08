#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <initializer_list>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned IndexType;

double fRand(double fMin, double fMax);

template <class T>
class Array {
        IndexType m_size;
        T *m_matrix;
    public:
        Array(IndexType size, bool fill);
        ~Array();
        Array operator-(Array &);
        T& operator[](const IndexType &index);
        void print(char * text) const;
        IndexType getSize() const;
};

template <class T>
class Matrix {
        IndexType m_rowSize;
        IndexType m_colSize;
        T **m_matrix;
    public:
        Matrix(IndexType rowSize, IndexType colSize, bool fill);
        Matrix(initializer_list<initializer_list<T>> list);
        ~Matrix();
        Matrix<T> operator*(Matrix<T> &);
        Array<T> operator*(Array<T> &);
        T *& operator[](const IndexType &);
        void print(char * text) const;
        IndexType getRows() const;
        IndexType getCols() const;
        void loadTrainingData(Matrix<double> *data, unsigned numberOfExamples);
};


#endif // MATRIX_H
