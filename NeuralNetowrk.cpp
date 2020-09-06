#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(unsigned inputSize, unsigned middleSize, unsigned outputSize):inputSize(inputSize),middleSize(middleSize),outputSize(outputSize){
    inputLayer = new Array(inputSize, 0.5);
    middleLayer = new Array(middleSize, 0.5);
    outputLayer = new Array(outputSize, 0.5);
    inputMiddleWeights = new Matrix(inputSize, middleSize, 0.5);
    middleOutputWeights = new Matrix(middleSize, outputSize, 0.5);
}

NeuralNetwork::~NeuralNetwork(){
    delete[] inputLayer;
    delete[] middleLayer;
    delete[] outputLayer;
    delete[] inputMiddleWeights;
    delete[] middleOutputWeights;
}
