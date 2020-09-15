/*
 * NeuralNetwork.cpp
 *
 *  Created on: Sep 14, 2020
 *      Author: wade4
 */
#include "NeuralNetwork.h"

const double lr = 0.1f;

template class NeuralNetwork<double>;

template<class T>
void NeuralNetwork<T>::shuffle(int *array, size_t n) {
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

template<class T>
NeuralNetwork<T>::NeuralNetwork(IndexType inputSize, IndexType middleSize, IndexType outputSize) : inputSize(inputSize), middleSize(middleSize), outputSize(outputSize),numTrainingSets(0) {
    inputLayer = new Array<T>(inputSize, 0);
    middleLayer = new Array<T>(middleSize, 0);
    outputLayer = new Array<T>(outputSize, 0);
    inputMiddleWeights = new Matrix<T>(inputSize, middleSize, 0, 1);
    middleOutputWeights = new Matrix<T>(middleSize, outputSize, 0, 1);
    hiddenLayerBias = new Array<T>(middleSize, -1);
    outputLayerBias = new Array<T>(outputSize, -1);
    deltaHidden = new Array<T>(middleSize, 0);
    deltaOutput = new Array<T>(outputSize, 0);
    trainingInput = NULL;
    trainingOutput = NULL;
}

template<class T>
NeuralNetwork<T>::~NeuralNetwork() {
    delete[] inputLayer;
    delete[] middleLayer;
    delete[] outputLayer;
    delete[] inputMiddleWeights;
    delete[] middleOutputWeights;
    if (!trainingInput)
        delete[] trainingInput;
    if (!trainingOutput)
        delete[] trainingOutput;
    delete[] hiddenLayerBias;
    delete[] outputLayerBias;
    delete[] deltaHidden;
    delete[] deltaOutput;
}

template<class T>
void NeuralNetwork<T>::loadTrainingData(Matrix<T> *input, Matrix<T> *output) {
    numTrainingSets = input->getRows();
    trainingInput = input;
    trainingOutput = output;
}

template<class T>
double NeuralNetwork<T>::sigmoid(T x) {
    return 1 / (1 + exp(-x));
}

template<class T>
Array<double>& NeuralNetwork<T>::sigmoid(Array<T>& layerIn) {
    Array<T> layerOut(layerIn);
    for (auto j = 0; j < layerIn.getRows(); j++) {
        layerOut[j] = sigmoid(layerIn[j]);
    }
    return layerOut;
}

template<class T>
double NeuralNetwork<T>::sigmoidDerivative(T x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

template<class T>
Array<double>& NeuralNetwork<T>::sigmoidDerivative(Array<T>& layerIn) {
    Array<double> layerOut(layerIn);
    for (auto j = 0; j < layerIn.getRows(); j++) {
        layerOut[j] = sigmoidDerivative(layerIn[j]);
    }
    return layerOut;
}

template<class T>
void NeuralNetwork<T>::train(IndexType epochs) {
    cout << "examples=" << numTrainingSets << endl;
    int *trainingSetOrder = new int[numTrainingSets];
    for (int o = 0; o < numTrainingSets; o++) {
        trainingSetOrder[o] = o;
    }
    for (int n = 0; n < epochs; n++) {
        shuffle(trainingSetOrder, numTrainingSets);
        for (int x = 0; x < numTrainingSets; x++) {
            int i = trainingSetOrder[x];

            cout << "epoch : " << n << " example : " << i << endl;
            trainingInput->print("training input");
            trainingOutput->print("training output");

            inputMiddleWeights->print("input middle weights");
            middleOutputWeights->print("middle output weights");

            // Forward pass
            for (auto k = 0; k < inputSize; k++) {
                (*inputLayer)[k] = (*trainingInput)[i][k];
            }

            middleLayer->setBias(hiddenLayerBias);
            (*middleLayer) = (*inputMiddleWeights) * (*inputLayer);
            (*middleLayer) = sigmoid(*middleLayer);
            middleLayer->print("middle layer");

            outputLayer->setBias(outputLayerBias);
            (*outputLayer) = (*middleOutputWeights) * (*middleLayer);
            (*outputLayer) = sigmoid(*outputLayer);
            outputLayer->print("output layer");

            // Backprop
            double netError = 0.0;
            for (int j = 0; j < outputSize; j++) {
                double errorOutput = ((*trainingOutput)[i][j] - (*outputLayer)[j]);
                (*deltaOutput)[j] = errorOutput * sigmoidDerivative((*outputLayer)[j]);
                netError += 0.5 * pow(errorOutput, 2);
            }
            deltaOutput->print("delta output layer");
            if ((n % 1000) == 0)
                cout << "network error = " << fixed << setprecision(12) << netError << endl;

            for (int j = 0; j < middleSize; j++) {
                double errorHidden = 0.0f;
                for (int k = 0; k < outputSize; k++) {
                    errorHidden += (*deltaOutput)[k] * (*middleOutputWeights)[j][k];
                }
                (*deltaHidden)[j] = errorHidden * sigmoidDerivative((*middleLayer)[j]);
            }
            deltaHidden->print("delta hidden layer");

            for (int j = 0; j < outputSize; j++) {
                (*outputLayerBias)[j] += (*deltaOutput)[j] * lr;
                for (int k = 0; k < middleSize; k++) {
                    (*middleOutputWeights)[k][j] += (*middleLayer)[k] * (*deltaOutput)[j] * lr;
                }
            }
            middleOutputWeights->print("middle output weights");

            for (int j = 0; j < middleSize; j++) {
                (*hiddenLayerBias)[j] += (*deltaHidden)[j] * lr;
                for (int k = 0; k < inputSize; k++) {
                    (*inputMiddleWeights)[k][j] += (*trainingInput)[i][k] * (*deltaHidden)[j] * lr;
                }
            }
            inputMiddleWeights->print("input middle weights");
            cout << "------------------------------------------------------------------------------------" << endl;
        }
    }
}

template<class T>
IndexType NeuralNetwork<T>::getInputSize() {
    return inputSize;
}

template<class T>
IndexType NeuralNetwork<T>::getMiddleSize() {
    return middleSize;
}

template<class T>
IndexType NeuralNetwork<T>::getOutputSize() {
    return outputSize;
}

