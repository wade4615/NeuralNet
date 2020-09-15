//============================================================================
// Name        : NeuralNet.cpp
// Author      : Christopher D. Wade
// Version     :
// Copyright   : 2020 Christopher D. Wade
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "Matrix.h"
#include "Array.h"
#include "NeuralNetwork.h"

using namespace std;

void networkTest() {
    Matrix<double, 2, 4> trainingInput = { { 0.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 1.0, 1.0 } };
    Matrix<double, 1, 4> trainingOutput = { { 0.0 }, { 0.0 }, { 0.0 }, { 1.0 } };
    NeuralNetwork<double,2,2,1,4> net;
    net.loadTrainingData(trainingInput, trainingOutput);
    cout << "Number of input neurons  : " << net.getInputSize() << endl;
    cout << "Number of hidden neurons : " << net.getMiddleSize() << endl;
    cout << "Number of output neurons : " << net.getOutputSize() << endl;
}

void matrixArrayTest() {
    Matrix<double,2,2> matrix1 = { { 1.0, 2.0 }, { 3.0, 4.0 } };
    Array<double,2> array1 = { 3.0, 4.0 };
    matrix1.print("matrix1");
    array1.print("array1");

    Array<double,2> array2 = matrix1 * array1;
    array2.print("Array2");
}

int main() {
    cout << "Neural Net v1.0" << endl;
    matrixArrayTest();
    networkTest();
    return 0;
}
