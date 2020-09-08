#include <iostream>
#include "NeuralNetwork.h"

using namespace std;

int main(){
    cout << "Neural Net v1.0" << endl;
    Matrix<double> trainingInput = {{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.0,1.0,1.0}};
    Matrix<double> trainingOutput = {{1.0},{2.0},{3.0},{4.0}};
    NeuralNetwork net(3,9,1);
    net.loadTrainingData(&trainingInput,&trainingOutput);
    net.train(10000);
    cout << "Number of input neurons  : " << net.getInputSize() << endl;
    cout << "Number of hidden neurons : " << net.getMiddleSize() << endl;
    cout << "Number of output neurons : " << net.getOutputSize() << endl;
    return 0;
}
