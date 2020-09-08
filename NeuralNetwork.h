#ifndef NEURALNETWORK_H_INCLUDED
#define NEURALNETWORK_H_INCLUDED

#include <iostream>
#include <list>
#include <cstdlib>
#include <math.h>
#include "Matrix.h"

class NeuralNetwork {
        Array<double> *inputLayer;
        Matrix<double> *inputMiddleWeights;
        Array<double> *middleLayer;
        Matrix<double> *middleOutputWeights;
        Array<double> *outputLayer;
        IndexType inputSize;
        IndexType middleSize;
        IndexType outputSize;
        IndexType numTrainingSets;
        Array<double> *hiddenLayerBias;
        Array<double> *outputLayerBias;
        Matrix<double> *trainingInput;
        Matrix<double> *trainingOutput;
        Array<double> *deltaHidden;
        Array<double> *deltaOutput;
    public:
        NeuralNetwork(IndexType inputSize, IndexType middleSize, IndexType outputSize);
        ~NeuralNetwork();
        void forward(Array<double> *inLayer, Array<double> *outLayer, Matrix<double> *weights, Array<double> *bias, IndexType size1, IndexType size2);
        void loadTrainingData(Matrix<double> *input, Matrix<double> *output);
        void train(IndexType epochs);
        double sigmoid(double x);
        double sigmoidDerivative(double x);
        IndexType getInputSize();
        IndexType getMiddleSize();
        IndexType getOutputSize();
};

#endif // NEURALNETWORK_H_INCLUDED
