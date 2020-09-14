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

template<class T> class Matrix;

template<class T>
class Array {
        IndexType m_numberOfElements;
        T *elements;
        Array<T> *bias;
    public:
        Array(IndexType numberOfElements, double low, double high);
        Array(IndexType numberOfElements, double value);
        Array(initializer_list<T> list);
        ~Array();
        Array operator-(Array&);
        Array<T> operator*(Matrix<T> &other);
        T& operator[](const IndexType &index);
        void setBias(Array<T> *other);
        void print(char *text) const;
        IndexType getSize() const;
};

template<class T>
class Matrix {
        IndexType m_rowSize;
        IndexType m_colSize;
        T **elements;
        Array<T> *bias;
    public:
        Matrix(IndexType rowSize, IndexType colSize, double low, double high);
        Matrix(IndexType rowSize, IndexType colSize, double value);
        Matrix(initializer_list<initializer_list<T>> list);
        ~Matrix();
        Matrix<T> operator*(Matrix<T> &other);
        Array<T> operator*(Array<T> &other);
        T*& operator[](const IndexType&);
        void print(char *text) const;
        IndexType getRows() const;
        IndexType getCols() const;
        void loadTrainingData(Matrix<double> *data, unsigned numberOfExamples);
};

#endif /* MATRIX_H_ */
