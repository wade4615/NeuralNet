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

Matrix Matrix::operator+(Matrix &other){
    Matrix sum(m_colSize, m_rowSize, 0.0);
    for (auto i = 0; i < m_rowSize; i++) {
        for (auto j = 0; j < m_colSize; j++) {
            sum(i,j) = this->m_matrix[i][j] + other(i,j);
        }
    }
    return sum;
}

Matrix Matrix::operator-(Matrix &other){
    Matrix diff(m_colSize, m_rowSize, 0.0);
    unsigned i,j;
    for (i = 0; i < m_rowSize; i++) {
        for (j = 0; j < m_colSize; j++) {
            diff(i,j) = this->m_matrix[i][j] - other(i,j);
        }
    }
    return diff;
}

Matrix Matrix::operator*(Matrix &other){
    Matrix multip(m_rowSize,other.getCols(),0.0);
    if(m_colSize == other.getRows()) {
        unsigned i,j,k;
        double temp = 0.0;
        for (i = 0; i < m_rowSize; i++)
        {
            for (j = 0; j < other.getCols(); j++)
            {
                temp = 0.0;
                for (k = 0; k < m_colSize; k++)
                {
                    temp += m_matrix[i][k] * other(k,j);
                }
                multip(i,j) = temp;
            }
        }
        return multip;
    }
    return *this;
}

Matrix Matrix::transpose(){
    Matrix Transpose(m_colSize,m_rowSize,0.0);
    for (unsigned i = 0; i < m_colSize; i++) {
        for (unsigned j = 0; j < m_rowSize; j++) {
            Transpose(i,j) = this->m_matrix[j][i];
        }
    }
    return Transpose;
}

Matrix Matrix::operator+(double scalar){
    Matrix result(m_rowSize,m_colSize,0.0);
    unsigned i,j;
    for (i = 0; i < m_rowSize; i++) {
        for (j = 0; j < m_colSize; j++) {
            result(i,j) = this->m_matrix[i][j] + scalar;
        }
    }
    return result;
}

Matrix Matrix::operator-(double scalar){
    Matrix result(m_rowSize,m_colSize,0.0);
    unsigned i,j;
    for (i = 0; i < m_rowSize; i++) {
        for (j = 0; j < m_colSize; j++) {
            result(i,j) = this->m_matrix[i][j] - scalar;
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar){
    Matrix result(m_rowSize,m_colSize,0.0);
    unsigned i,j;
    for (i = 0; i < m_rowSize; i++) {
        for (j = 0; j < m_colSize; j++) {
            result(i,j) = this->m_matrix[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator/(double scalar){
    Matrix result(m_rowSize,m_colSize,0.0);
    unsigned i,j;
    for (i = 0; i < m_rowSize; i++) {
        for (j = 0; j < m_colSize; j++) {
            result(i,j) = this->m_matrix[i][j] / scalar;
        }
    }
    return result;
}

double& Matrix::operator()(const unsigned &rowNo, const unsigned & colNo)
{
    return this->m_matrix[rowNo][colNo];
}

void Matrix::print() const{
    cout << "Matrix: " << endl;
    for (unsigned i = 0; i < m_rowSize; i++) {
        for (unsigned j = 0; j < m_colSize; j++) {
            cout << "[" << m_matrix[i][j] << "] ";
        }
        cout << endl;
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
