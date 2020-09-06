#include "Matrix.h"

Matrix::Matrix(unsigned rowSize, unsigned colSize, double initial){
    m_rowSize = rowSize;
    m_colSize = colSize;
    m_matrix.resize(rowSize);
    for (auto i = 0; i < m_matrix.size(); i++) {
        m_matrix[i].resize(colSize, initial);
    }
}
Matrix::~Matrix() {
}

vector<double>& Matrix::operator[](const unsigned &index){
    return m_matrix[index];
}

Matrix Matrix::operator*(Matrix &other){
    Matrix multip(m_rowSize,other.getCols(),0.0);
    if(m_colSize == other.getRows()) {
        unsigned i,j,k;
        double temp = 0.0;
        for (i = 0; i < m_rowSize; i++) {
            for (j = 0; j < other.getCols(); j++) {
                temp = 0.0;
                for (k = 0; k < m_colSize; k++) {
                    temp += m_matrix[i][k] * other[k][j];
                }
                multip[i][j] = temp;
            }
        }
        return multip;
    }
    return *this;
}

Array Matrix::operator*(Array &other){
    Array c(other.getSize(),0.0);
    if(m_colSize == other.getSize()) {
        for(auto i=0; i<other.getSize(); i++) {
            c[i] = 0;
            for(auto j=0; j<m_rowSize; j++) {
                c[i] += m_matrix[i][j] * other[j];
            }
        }
    }
    return c;
}

void Matrix::print() const {
    cout << "Matrix:" << endl;
    string delimiter = "";
    for (auto i = 0; i < m_rowSize; i++) {
        delimiter = "";
        for (auto j = 0; j < m_colSize; j++) {
            cout << delimiter << m_matrix[i][j];
            delimiter = ",";
        }
        cout << std::endl;
    }
}
unsigned Matrix::getRows() const{
    return m_rowSize;
}

unsigned Matrix::getCols() const{
    return m_colSize;
}




Array::Array(unsigned size, double initial){
    m_size = size;
    m_matrix.resize(size);
}

Array::~Array() {
}

double& Array::operator[](const unsigned &index){
    return m_matrix[index];
}

void Array::print() const {
    cout << "Array:" << endl;
    string delimiter = "";
    for (auto j = 0; j < m_size; j++) {
        cout << delimiter << m_matrix[j];
        delimiter = ",";
    }
    cout << endl;
}

unsigned Array::getSize() const {
    return m_size;
}

