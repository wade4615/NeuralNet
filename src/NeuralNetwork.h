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

template<class T>
class NeuralNetwork {
        Array<T> *inputLayer;
        Matrix<T> *inputMiddleWeights;
        Array<T> *middleLayer;
        Matrix<T> *middleOutputWeights;
        Array<T> *outputLayer;
        IndexType inputSize;
        IndexType middleSize;
        IndexType outputSize;
        IndexType numTrainingSets;
        Array<T> *hiddenLayerBias;
        Array<T> *outputLayerBias;
        Matrix<T> *trainingInput;
        Matrix<T> *trainingOutput;
        Array<T> *deltaHidden;
        Array<T> *deltaOutput;
    public:
        NeuralNetwork(IndexType inputSize, IndexType middleSize, IndexType outputSize);
        ~NeuralNetwork();
        void loadTrainingData(Matrix<T> *input, Matrix<T> *output);
        void train(IndexType epochs);
        IndexType getInputSize();
        IndexType getMiddleSize();
        IndexType getOutputSize();
    private:
        void shuffle(int *array, size_t n);
        double sigmoid(T x);
        double sigmoidDerivative(T x);
        Array<double>& sigmoid(Array<T>& layerIn);
        Array<double>& sigmoidDerivative(Array<T>& layerIn);
};

#endif /* NEURALNETWORK_CPP_ */
