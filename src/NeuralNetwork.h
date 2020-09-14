/*
 * NeuralNetwork.cpp
 *
 *  Created on: Sep 14, 2020
 *      Author: wade4
 */

#ifndef NEURALNETWORK_CPP_
#define NEURALNETWORK_CPP_

#include <iostream>
#include <list>
#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <limits>
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
        void loadTrainingData(Matrix<double> *input, Matrix<double> *output);
        void train(IndexType epochs);
        IndexType getInputSize();
        IndexType getMiddleSize();
        IndexType getOutputSize();
    private:
        void shuffle(int *array, size_t n);
        double sigmoid(double x);
        double sigmoidDerivative(double x);
        Array<double>& sigmoid(Array<double> *layerIn);
        Array<double>& sigmoidDerivative(Array<double> *layerIn);
};

#endif /* NEURALNETWORK_CPP_ */
