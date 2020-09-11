#include <iostream>
#include "NeuralNetwork.h"

using namespace std;

int main(){
    cout << "Neural Net v1.0" << endl;
    Matrix<double> trainingInput = {{0.0,0.0},{0.0,1.0},{1.0,0.0},{1.0,1.0}};
    Matrix<double> trainingOutput = {{0.0},{0.0},{0.0},{1.0}};
    NeuralNetwork net(2,4,1);
    net.loadTrainingData(&trainingInput,&trainingOutput);
    net.train(1);
    cout << "Number of input neurons  : " << net.getInputSize() << endl;
    cout << "Number of hidden neurons : " << net.getMiddleSize() << endl;
    cout << "Number of output neurons : " << net.getOutputSize() << endl;
    return 0;
}
