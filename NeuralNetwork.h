#ifndef NEURALNETWORK_H_INCLUDED
#define NEURALNETWORK_H_INCLUDED

#include "Matrix.h"

class NeuralNetwork {
        Array<double> *inputLayer;
        Matrix<double> *inputMiddleWeights;
        Array<double> *middleLayer;
        Matrix<double> *middleOutputWeights;
        Array<double> *outputLayer;
        unsigned inputSize;
        unsigned middleSize;
        unsigned outputSize;
    public:
        NeuralNetwork(unsigned inputSize, unsigned middleSize, unsigned outputSize);
        ~NeuralNetwork();
};

#endif // NEURALNETWORK_H_INCLUDED
