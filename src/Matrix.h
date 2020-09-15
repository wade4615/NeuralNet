/*
 * Matrix.h
 *
 *  Created on: Sep 14, 2020
 *      Author: wade4
 */
#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <initializer_list>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned IndexType;

double fRand(double fMin, double fMax);

template<class > class Array;

template<class T>
class Matrix {
    protected:
        IndexType m_rowSize;
        IndexType m_colSize;
        T **elements;
        Array<T> *bias;
    public:
        Matrix();
        Matrix(IndexType rowSize, IndexType colSize, double low, double high);
        Matrix(IndexType rowSize, IndexType colSize, double value);
        Matrix(initializer_list<initializer_list<T>> list);
        T*& operator[](const IndexType& index);
        Array<T> operator*(Array<T> &other);
        void print(char *text) const;
        IndexType getRows() const;
        IndexType getCols() const;
        void setBias(Array<T> *other);
};

template<class T>
class Array : public Matrix<T> {
    public:
        Array();
        Array(IndexType numberOfElements, double low, double high);
        Array(IndexType numberOfElements, double value);
        Array(initializer_list<T> list);
        T& operator[](const IndexType &index);
};

#endif /* MATRIX_H_ */
