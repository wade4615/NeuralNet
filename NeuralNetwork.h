#ifndef NEURALNETWORK_H_INCLUDED
#define NEURALNETWORK_H_INCLUDED

#include "Matrix.h"

class NeuralNetwork {
        Array *inputLayer;
        Matrix *inputMiddleWeights;
        Array *middleLayer;
        Matrix *middleOutputWeights;
        Array *outputLayer;
        unsigned inputSize;
        unsigned middleSize;
        unsigned outputSize;
    public:
        NeuralNetwork(unsigned inputSize, unsigned middleSize, unsigned outputSize);
        ~NeuralNetwork();
};

#endif // NEURALNETWORK_H_INCLUDED
