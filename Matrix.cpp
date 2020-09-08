#include "Matrix.h"

double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template class Matrix<double>;

template <class T>
Matrix<T>::Matrix(unsigned rowSize, unsigned colSize, double low, double high){
    m_rowSize = rowSize;
    m_colSize = colSize;
    m_matrix = new T *[rowSize];
    for (IndexType i = 0; i < rowSize; i++) {
        m_matrix[i] = new T[colSize];
        for (IndexType j = 0; j < colSize; j++) {
            m_matrix[i][j] = fRand(low, high);
        }
    }
}

template <class T>
Matrix<T>::Matrix(unsigned rowSize, unsigned colSize, double value){
    m_rowSize = rowSize;
    m_colSize = colSize;
    m_matrix = new T *[rowSize];
    for (IndexType i = 0; i < rowSize; i++) {
        m_matrix[i] = new T[colSize];
        for (IndexType j = 0; j < colSize; j++) {
            m_matrix[i][j] = value;
        }
    }
}

template <class T>
Matrix<T>::Matrix(initializer_list<initializer_list<T>> list){
    this->m_rowSize = (int)list.size();
    this->m_colSize = (int)(list.begin())->size();
    m_matrix = new T *[m_rowSize];
    for (IndexType i = 0; i < m_rowSize; i++) {
        m_matrix[i] = new T[m_colSize];
        for (IndexType j = 0; j < m_colSize; j++) {
            m_matrix[i][j] = ((list.begin()+i)->begin())[j];
        }
    }
}

template <class T>
Matrix<T>::~Matrix() {
    for (IndexType i = 0; i < m_rowSize; i++) {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}

template <class T>
T *& Matrix<T>::operator[](const IndexType &index){
    return m_matrix[index];
}

template <class T>
void Matrix<T>::print(char * text) const {
    cout << text << endl;
    string delimiter = "";
    for (IndexType i = 0; i < m_rowSize; i++) {
        delimiter = "";
        for (IndexType j = 0; j < m_colSize; j++) {
            cout << delimiter << m_matrix[i][j];
            delimiter = ",";
        }
        cout << std::endl;
    }
}

template <class T>
IndexType Matrix<T>::getRows() const{
    return m_rowSize;
}

template <class T>
IndexType Matrix<T>::getCols() const{
    return m_colSize;
}


template class Array<double>;

template <class T>
Array<T>::Array(IndexType size, double low, double high){
    m_size = size;
    m_list = new T[m_size];
    for (int i=0; i<m_size; i++) {
        m_list[i] = fRand(low, high);
    }
}

template <class T>
Array<T>::Array(IndexType size, double value){
    m_size = size;
    m_list = new T[m_size];
    for (int i=0; i<m_size; i++) {
        m_list[i] = value;
    }
}

template <class T>
Array<T>::~Array() {
    delete[] m_list;
}

template <class T>
T& Array<T>::operator[](const IndexType &index){
    return m_list[index];
}

template <class T>
void Array<T>::print(char * text) const {
    cout << text << endl;
    string delimiter = "";
    if (m_size>0){
        for (IndexType j = 0; j < m_size; j++) {
            cout << delimiter << m_list[j];
            delimiter = ",";
        }
    } else {
        cout << "size=0" << endl;
    }
    cout << endl;
}

template <class T>
unsigned Array<T>::getSize() const {
    return m_size;
}

