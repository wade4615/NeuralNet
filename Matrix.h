#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

#include <iostream>
#include <random>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Array;

class Matrix {
    protected:
        double** values;
        int rows;
        int columns;
    public:
        Matrix(int rows, int columns);
        Matrix(const Matrix& rhs);
        ~Matrix();
        void randomFill(double lowerBound, double upperBound);
        void show();
        Matrix& operator=(const Matrix& rhs);
        double *& operator [](int index);
        Matrix operator*(Matrix &x);
        Array operator*(Array &x);
};

class Array {
    protected:
        double* values;
    public:
        int entries;
        Array(int entries);
        Array(const Array& rhs);
        ~Array();
        void randomFill(double lowerBound, double upperBound);
        void show();
        Array& operator=(const Array& rhs);
        double& operator [](int index);
        double operator*(Array &x);
};
#endif // MATRIX_H
