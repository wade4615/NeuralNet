/*
 * NeuralNetwork.h
 *
 *  Created on: Sep 15, 2020
 *      Author: wade4
 */

#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include <iostream>
#include <list>
#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <limits>
#include "Matrix.h"
#include "Array.h"

template<class T, IndexType I, IndexType M, IndexType O, IndexType S>
class NeuralNetwork {
        Array<T,I> inputLayer;
        Matrix<T,I,M>  inputMiddleWeights;
        Array<T,M>   middleLayer;
        Matrix<T,M,O>  middleOutputWeights;
        Array<T,O>   outputLayer;
        IndexType  inputSize;
        IndexType  middleSize;
        IndexType  outputSize;
        IndexType  numTrainingSets;
        Array<T,M>   hiddenLayerBias;
        Array<T,O>   outputLayerBias;
        Matrix<T,I,S>  trainingInput;
        Matrix<T,O,S>  trainingOutput;
        Array<T,M>   deltaHidden;
        Array<T,O>   deltaOutput;
    public:
        NeuralNetwork() {
        	 inputSize = I;
        	 middleSize = M;
        	 outputSize = O;
        	 numTrainingSets = S;
        }
        ~NeuralNetwork() {
        }
        void shuffle(int *array, IndexType n) {
            if (n > 1) {
                size_t i;
                for (i = 0; i < n - 1; i++) {
                    size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
                    int t = array[j];
                    array[j] = array[i];
                    array[i] = t;
                }
            }
        }
        void loadTrainingData(Matrix<T,I,S>& input, Matrix<T,O,S>& output) {
            numTrainingSets = S;
            trainingInput = input;
            trainingOutput = output;
        }
        double sigmoid(T x) {
            return 1 / (1 + exp(-x));
        }
        double sigmoidDerivative(T x) {
            return sigmoid(x) * (1 - sigmoid(x));
        }
        Array<T,I>& sigmoid(Array<T,I>& layerIn) {
            Array<T,I> layerOut(layerIn);
            for (auto j = 0; j < layerIn.getRows(); j++) {
                layerOut[j] = sigmoid(layerIn[j]);
            }
            return layerOut;
        }
        Array<T,I>& sigmoidDerivative(Array<T,I>& layerIn) {
            Array<T,I> layerOut(layerIn);
            for (auto j = 0; j < layerIn.getRows(); j++) {
                layerOut[j] = sigmoidDerivative(layerIn[j]);
            }
            return layerOut;
        }
        IndexType getInputSize() {
            return inputSize;
        }
        IndexType getMiddleSize() {
            return middleSize;
        }
        IndexType getOutputSize() {
            return outputSize;
        }

};
#endif /* NEURALNETWORK_H_ */
