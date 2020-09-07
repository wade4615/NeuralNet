#include "Matrix.h"

template class Matrix<double>;

template <class T>
Matrix<T>::Matrix(unsigned rowSize, unsigned colSize){
    m_rowSize = rowSize;
    m_colSize = colSize;
    m_matrix = new T *[rowSize];
    for (unsigned i = 0; i < rowSize; i++) {
        m_matrix[i] = new T[colSize];
    }
}

template <class T>
Matrix<T>::~Matrix() {
    for (unsigned i = 0; i < m_rowSize; i++) {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}

template <class T>
T *& Matrix<T>::operator[](const unsigned &index){
    return m_matrix[index];
}

template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &other){
    Matrix<T> *multip = new Matrix<T>(m_rowSize,other.getCols());
    if(m_colSize == other.getRows()) {
        unsigned i,j,k;
        double temp = 0.0;
        for (i = 0; i < m_rowSize; i++) {
            for (j = 0; j < other.getCols(); j++) {
                temp = 0.0;
                for (k = 0; k < m_colSize; k++) {
                    temp += m_matrix[i][k] * other[k][j];
                }
                (*multip)[i][j] = temp;
            }
        }
        return *multip;
    }
    return *this;
}

template <class T>
Array<T> Matrix<T>::operator*(Array<T> &other){
    Array<T> c(other.getSize());
    if(m_colSize == other.getSize()) {
        for(unsigned i=0; i<other.getSize(); i++) {
            c[i] = 0;
            for(unsigned j=0; j<m_rowSize; j++) {
                c[i] += m_matrix[i][j] * other[j];
            }
        }
    }
    return c;
}

template <class T>
void Matrix<T>::print() const {
    cout << "Matrix:" << endl;
    string delimiter = "";
    for (unsigned i = 0; i < m_rowSize; i++) {
        delimiter = "";
        for (unsigned j = 0; j < m_colSize; j++) {
            cout << delimiter << m_matrix[i][j];
            delimiter = ",";
        }
        cout << std::endl;
    }
}

template <class T>
unsigned Matrix<T>::getRows() const{
    return m_rowSize;
}

template <class T>
unsigned Matrix<T>::getCols() const{
    return m_colSize;
}


template class Array<double>;

template <class T>
Array<T>::Array(unsigned size){
    m_size = size;
    m_matrix = new T[m_size];
}

template <class T>
Array<T>::~Array() {
    delete[] m_matrix;
}

template <class T>
T& Array<T>::operator[](const unsigned &index){
    return m_matrix[index];
}

template <class T>
void Array<T>::print() const {
    cout << "Array:" << endl;
    string delimiter = "";
    for (unsigned j = 0; j < m_size; j++) {
        cout << delimiter << m_matrix[j];
        delimiter = ",";
    }
    cout << endl;
}

template <class T>
unsigned Array<T>::getSize() const {
    return m_size;
}

