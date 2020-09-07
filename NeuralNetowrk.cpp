#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(unsigned inputSize, unsigned middleSize, unsigned outputSize):inputSize(inputSize),middleSize(middleSize),outputSize(outputSize){
    inputLayer = new Array<double>(inputSize);
    middleLayer = new Array<double>(middleSize);
    outputLayer = new Array<double>(outputSize);
    inputMiddleWeights = new Matrix<double>(inputSize, middleSize, true);
    middleOutputWeights = new Matrix<double>(middleSize, outputSize, true);
}

NeuralNetwork::~NeuralNetwork(){
    delete[] inputLayer;
    delete[] middleLayer;
    delete[] outputLayer;
    delete[] inputMiddleWeights;
    delete[] middleOutputWeights;
}
