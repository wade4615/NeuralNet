/*
 * Matrix.cpp
 *
 *  Created on: Sep 14, 2020
 *      Author: wade4
 */
#include "Matrix.h"

double fRand(double fMin, double fMax) {
    double f = (double) rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template class Array<double> ;

template<class T>
Array<T>::Array(){
}

template<class T>
Array<T>::Array(IndexType numberOfElements, double low, double high):Matrix<T>(numberOfElements, 1, low, high) {
}

template<class T>
Array<T>::Array(IndexType numberOfElements, double value):Matrix<T>(numberOfElements, 1, value) {
}

template<class T>
Array<T>::Array(initializer_list<T> list) {
    this->m_rowSize = (int) list.size();
    this->m_colSize = 1;
    this->elements = new T  *[this->m_rowSize];
    auto count = 0;
    for (auto element : list) {
        this->elements[count] = new T[this->m_colSize];
        this->elements[count][0] = element;
        count++;
    }
}

template<class T>
T& Array<T>::operator[](const IndexType &index) {
    return this->elements[index][0];
}

template class Matrix<double>;

template<class T>
Matrix<T>::Matrix(){
    bias = NULL;
    m_rowSize = 0;
    m_colSize = 0;
    elements = NULL;
}

template<class T>
Matrix<T>::Matrix(unsigned rowSize, unsigned colSize, double low, double high) {
    bias = NULL;
    m_rowSize = rowSize;
    m_colSize = colSize;
    elements = new T  *[m_rowSize];
    for (auto i = 0; i < rowSize; i++) {
        elements[i] = new T[m_colSize];
        for (auto j = 0; j < colSize; j++) {
            elements[i][j] = fRand(low, high);
        }
    }
}

template<class T>
Matrix<T>::Matrix(unsigned rowSize, unsigned colSize, double value) {
    bias = NULL;
    m_rowSize = rowSize;
    m_colSize = colSize;
    elements = new T  *[m_rowSize];
    for (auto i = 0; i < rowSize; i++) {
        elements[i] = new T[m_colSize];
        for (auto j = 0; j < colSize; j++) {
            elements[i][j] = value;
        }
    }
}

template<class T>
Matrix<T>::Matrix(initializer_list<initializer_list<T>> list) {
    this->bias = NULL;
    this->m_rowSize = (int) list.size();
    this->m_colSize = (int) (list.begin())->size();
    elements = new T  *[m_rowSize];
    for (auto i = 0; i < m_rowSize; i++) {
        elements[i] = new T[m_colSize];
        for (auto j = 0; j < m_colSize; j++) {
            elements[i][j] = ((list.begin() + i)->begin())[j];
        }
    }
}

template<class T>
T *& Matrix<T>::operator[](const IndexType& index){
    return elements[index];
}

template<class T>
Array<T> Matrix<T>::operator*(Array<T> &other) {
    Array<T> *temp = new Array<T>(other.getRows(), 0.0);
    for (auto i = 0; i < other.getRows(); i++) {
        double acumulate = 0;
        if (bias == NULL)
            acumulate = 0;
        else
            acumulate = (*bias)[i];
        for (auto j = 0; j < m_rowSize; j++) {
            acumulate += elements[i][j] * other[j];
        }
        (*temp)[i] += acumulate;
    }
    return *temp;
}

template<class T>
IndexType Matrix<T>::getRows() const {
    return m_rowSize;
}

template<class T>
IndexType Matrix<T>::getCols() const {
    return m_colSize;
}

template<class T>
void Matrix<T>::print(char *text) const {
    cout << text << endl;
    string delimiter = "";
    for (auto i = 0; i < m_rowSize; i++) {
        delimiter = "";
        for (auto j = 0; j < m_colSize; j++) {
            cout << delimiter << elements[i][j];
            delimiter = ",";
        }
        cout << std::endl;
    }
}

template<class T>
void Matrix<T>::setBias(Array<T> *other) {
    bias = other;
}
