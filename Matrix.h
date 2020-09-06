#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

#include <stdio.h>
#include <fstream> // for file access
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

class Array {
    protected:
        unsigned m_size;
        vector<double> m_matrix;
    public:
        Array(unsigned size, double initial);
        ~Array();
        Array operator-(Array &);
        double& operator[](const unsigned &);
        void print() const;
        unsigned getSize() const;
};

class Matrix {
    protected:
        unsigned m_rowSize;
        unsigned m_colSize;
        vector<vector<double>> m_matrix;
    public:
        Matrix(unsigned rowSize, unsigned colSize, double initial);
        ~Matrix();
        Matrix operator*(Matrix &);
        Array operator*(Array &);
        vector<double>& operator[](const unsigned &);
        void print() const;
        unsigned getRows() const;
        unsigned getCols() const;
};
#endif // MATRIX_H
