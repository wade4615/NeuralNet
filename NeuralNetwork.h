#ifndef NEURALNETWORK_H_INCLUDED
#define NEURALNETWORK_H_INCLUDED

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
        void forwardPropagate(Array<double> *inLayer, Array<double> *outLayer, Matrix<double> *weights, Array<double> *bias, IndexType size1, IndexType size2);
        void backPropagate(Array<double> *layer,Matrix<double> *weights,Array<double> *delta,Array<double> *bias,IndexType size1,IndexType size2);
        double computeOutputError(int epoch,int trainingExample,Matrix<double> *expectedOutput,Array<double> *layer, IndexType size1);
        double sigmoid(double x);
        double sigmoidDerivative(double x);

};

#endif // NEURALNETWORK_H_INCLUDED
