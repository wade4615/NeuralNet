#include "Matrix.h"

Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns) {
    values = new double*[rows];
    for(auto i=0; i< rows; i++){
        values[i] = new double[columns];
    }
}

Matrix::Matrix(const Matrix& rhs) : rows(rhs.rows), columns(rhs.columns) {
    values = new double*[rows];
    for(auto i=0; i< rows; i++){
        values[i] = new double[columns];
    }
    for (auto i = 0; i < rows; i++) {
        for (auto j = 0; j < columns; j++) {
                values[i][j] = rhs.values[i][j];
        }
    }
}

Matrix::~Matrix() {
    for(auto i=0; i< rows; i++){
        delete[] values[i];
    }
    delete[] values;
}

double randDouble(double a, double b) {
	return ((double)rand() / RAND_MAX) * (b - a) + a;
}

void Matrix::randomFill(double lowerBound, double upperBound){
    srand (time(NULL));
    for(auto i=0; i< rows; i++){
        for(auto j=0; j< columns; j++){
            values[i][j] = randDouble(lowerBound, upperBound);
        }
    }
}

void Matrix::show() {
    std::string delimiter = "";
    for (auto i = 0; i < rows; i++) {
        delimiter = "";
        for (auto j = 0; j < columns; j++) {
            std::cout << delimiter << values[i][j];
            delimiter = ",";
        }
        std::cout << std::endl;
    }
}

Matrix& Matrix::operator=(const Matrix& rhs) {
    if (&rhs == this) {
        return *this;
    }
    for(auto i=0; i< rows; i++){
        delete[] values[i];
    }
    delete[] values;

    values = new double*[rhs.rows];
    for(auto i=0; i< rows; i++){
        values[i] = new double[rhs.columns];
    }
    for (auto i = 0; i < rhs.rows; i++) {
        for (auto j = 0; j < rhs.columns; j++) {
                values[i][j] = rhs.values[i][j];
        }
    }
    return *this;
}

double*& Matrix::operator [](int index){
    return values[index];
}

Matrix Matrix::operator*(Matrix &rhs) {
    if (columns != rhs.rows) {
        throw std::length_error("Matrices shapes mismatch");
    } else {
        Matrix Temp1(rows,rhs.columns);

        int sum = 0;
        for(auto i=0;i<rows;i++) {
            for(auto j=0; j<rhs.columns;j++) {
                sum = 0;
                for(auto k=0; k<rows;k++) {
                    sum += values[i][k]*rhs[k][j];
                }
                Temp1[i][j] = sum;
            }
        }
        return Temp1;
    }
    return rhs;
}


Array Matrix::operator*(Array &rhs) {
    if (columns != rhs.entries) {
        throw std::length_error("Matrices shapes mismatch");
    } else {
        Array result(rhs.entries);

        for (auto i=0;i<rhs.entries;i++) {
            result[i]=0.0;
        }
        for (auto i=0;i<rows;i++) {
            for (auto j=0;j<columns;j++){
                result[i]+=values[i][j]*rhs[j];
            }
        }
        return result;
    }
    return rhs;
}

Array::Array(int entries) : entries(entries) {
    values = new double[entries];
}

Array::Array(const Array& rhs) : entries(entries) {
    values = new double[entries];
    for (auto i = 0; i < entries; i++) {
        values[i] = rhs.values[i];
    }
}

Array::~Array() {
    delete[] values;
}

void Array::randomFill(double lowerBound, double upperBound){
    srand (time(NULL));
    for(auto i=0; i< entries; i++){
        values[i] = randDouble(lowerBound, upperBound);
    }
}

void Array::show() {
    std::string delimiter = "";
    for (auto i = 0; i < entries; i++) {
        std::cout << delimiter << values[i];
        delimiter = ",";
    }
    std::cout << std::endl;
}

Array& Array::operator=(const Array& rhs) {
    if (&rhs == this) {
        return *this;
    }
    delete[] values;

    values = new double[rhs.entries];
    for (auto i = 0; i < rhs.entries; i++) {
        values[i] = rhs.values[i];
    }
    return *this;
}

double& Array::operator [](int index){
    return values[index];
}

double Array::operator*(Array &rhs) {
    if (entries != rhs.entries) {
        throw std::length_error("Matrices shapes mismatch");
    } else {
        double sum = 0.0;
        for(auto i=0;i<entries;i++) {
            sum += values[i]*rhs[i];
        }
        return sum;
    }
    return -1;
}
