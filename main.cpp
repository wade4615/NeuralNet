#include <iostream>
#include "NeuralNetwork.h"

using namespace std;

int main(){
    cout << "Neural Net v1.0" << endl;
    Matrix<double> trainingInput = {{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.0,1.0,1.0}};
    Matrix<double> trainingOutput = {{1.0},{2.0},{3.0},{4.0}};
    NeuralNetwork net(3,4,1);
    net.loadTrainingData(&trainingInput,&trainingOutput);
    net.train(10);
    return 0;
}
