#include <iostream>
#include "NeuralNetwork.h"

using namespace std;

void networkTest()
{
    Matrix<double> trainingInput = {{0.0,0.0},{0.0,1.0},{1.0,0.0},{1.0,1.0}};
    Matrix<double> trainingOutput = {{0.0},{0.0},{0.0},{1.0}};
    NeuralNetwork net(2,2,1);
    net.loadTrainingData(&trainingInput,&trainingOutput);
    net.train(1);
    cout << "Number of input neurons  : " << net.getInputSize() << endl;
    cout << "Number of hidden neurons : " << net.getMiddleSize() << endl;
    cout << "Number of output neurons : " << net.getOutputSize() << endl;
}

void matrixArrayTest()
{
    Matrix<double> matrix1 = {{1.0,2.0},{3.0,4.0}};
    Array<double> array1 = {3.0,4.0};
    matrix1.print("matrix1");
    array1.print("array1");

    Array<double> array2 = matrix1*array1;
    array2.print("Array2");
    Array<double> array3 = array1*matrix1;
    array2.print("Array3");
}

int main()
{
    cout << "Neural Net v1.0" << endl;
    matrixArrayTest();
    networkTest();
    return 0;
}
