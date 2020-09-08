#include "NeuralNetwork.h"

const double lr = 0.1f;

void shuffle(int *array, size_t n) {
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

NeuralNetwork::NeuralNetwork(unsigned inputSize, unsigned middleSize, unsigned outputSize):inputSize(inputSize),middleSize(middleSize),outputSize(outputSize){
    inputLayer = new Array<double>(inputSize,false);
    middleLayer = new Array<double>(middleSize,false);
    outputLayer = new Array<double>(outputSize,false);
    inputMiddleWeights = new Matrix<double>(inputSize, middleSize, true);
    middleOutputWeights = new Matrix<double>(middleSize, outputSize, true);
    hiddenLayerBias = new Array<double>(middleSize, true);
    outputLayerBias = new Array<double>(outputSize, true);
    deltaHidden = new Array<double>(middleSize,false);
    deltaOutput = new Array<double>(outputSize,false);
}

NeuralNetwork::~NeuralNetwork(){
    delete[] inputLayer;
    delete[] middleLayer;
    delete[] outputLayer;
    delete[] inputMiddleWeights;
    delete[] middleOutputWeights;
    if (!trainingInput) delete[] trainingInput;
    if (!trainingOutput) delete[] trainingOutput;
    delete[] hiddenLayerBias;
    delete[] outputLayerBias;
    delete[] deltaHidden;
    delete[] deltaOutput;
}

void NeuralNetwork::loadTrainingData(Matrix<double> *input, Matrix<double> *output){
    numTrainingSets = input->getRows();
    trainingInput = input;
    trainingOutput = output;
}

double NeuralNetwork::sigmoid(double x) {
    return 1/(1+exp(-x));
}

double NeuralNetwork::sigmoidDerivative(double x) {
    return sigmoid(x)*(1-sigmoid(x));
}

void NeuralNetwork::train(IndexType epochs){
    int *trainingSetOrder = new int[numTrainingSets];
    for (int o=0; o < numTrainingSets; o++) {
        trainingSetOrder[o] = o;
    }
    for (int n=0; n < epochs; n++) {
        shuffle(trainingSetOrder,numTrainingSets);
        for (int x=0; x<numTrainingSets; x++) {
            int i = trainingSetOrder[x];

            // Forward pass
            for (int j=0; j<middleSize; j++) {
                double activation=(*hiddenLayerBias)[j];
                for (int k=0; k<inputSize; k++) {
                    activation+=(*trainingInput)[i][k]*(*inputMiddleWeights)[k][j];
                }
                (*middleLayer)[j] = sigmoid(activation);
            }

            for (int j=0; j<outputSize; j++) {
                double activation=(*outputLayerBias)[j];
                for (int k=0; k<middleSize; k++) {
                    activation+=(*middleLayer)[k]*(*middleOutputWeights)[k][j];
                }
                (*outputLayer)[j] = sigmoid(activation);
            }

            // Backprop
            double average = 0.0;
            for (int j=0; j<outputSize; j++) {
                double errorOutput = ((*trainingOutput)[i][j]-(*outputLayer)[j]);
                (*deltaOutput)[j] = errorOutput*sigmoidDerivative((*outputLayer)[j]);
                average += (*deltaOutput)[j];
            }
            average /= outputSize;
            average *= 100;
            cout << "error average =" << average << "%" << endl;

            for (int j=0; j<middleSize; j++) {
                double errorHidden = 0.0f;
                for(int k=0; k<outputSize; k++) {
                    errorHidden+=(*deltaOutput)[k]*(*middleOutputWeights)[j][k];
                }
                (*deltaHidden)[j] = errorHidden*sigmoidDerivative((*middleLayer)[j]);
            }

            for (int j=0; j<outputSize; j++) {
                (*outputLayerBias)[j] += (*deltaOutput)[j]*lr;
                for (int k=0; k<middleSize; k++) {
                    (*middleOutputWeights)[k][j]+=(*middleLayer)[k]*(*deltaOutput)[j]*lr;
                }
            }

            for (int j=0; j<middleSize; j++) {
                (*hiddenLayerBias)[j] += (*deltaHidden)[j]*lr;
                for(int k=0; k<inputSize; k++) {
                    (*inputMiddleWeights)[k][j]+=(*trainingInput)[i][k]*(*deltaHidden)[j]*lr;
                }
            }
        }
    }
}
