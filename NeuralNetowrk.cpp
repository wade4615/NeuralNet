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

NeuralNetwork::NeuralNetwork(IndexType inputSize, IndexType middleSize, IndexType outputSize):inputSize(inputSize),middleSize(middleSize),outputSize(outputSize){
    inputLayer = new Array<double>(inputSize,0);
    middleLayer = new Array<double>(middleSize,0);
    outputLayer = new Array<double>(outputSize,0);
    inputMiddleWeights = new Matrix<double>(inputSize, middleSize, 0, 1);
    middleOutputWeights = new Matrix<double>(middleSize, outputSize, 0, 1);
    hiddenLayerBias = new Array<double>(middleSize, -1);
    outputLayerBias = new Array<double>(outputSize, -1);
    deltaHidden = new Array<double>(middleSize,0);
    deltaOutput = new Array<double>(outputSize,0);
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

void NeuralNetwork::forward(Array<double> *inLayer, Array<double> *outLayer, Matrix<double> *weights, Array<double> *bias, IndexType size1, IndexType size2){
    for (int j=0; j<size1; j++) {
        double activation=(*bias)[j];
        for (int k=0; k<size2; k++) {
            activation+=(*inLayer)[k]*(*weights)[k][j];
        }
        (*outLayer)[j] = sigmoid(activation);
    }
}

void NeuralNetwork::train(IndexType epochs){
    int *trainingSetOrder = new int[numTrainingSets];
    for (int o=0; o < numTrainingSets; o++) {
        trainingSetOrder[o] = o;
    }
    for (int n=1; n <= epochs; n++) {
        shuffle(trainingSetOrder,numTrainingSets);
        for (int x=0; x<numTrainingSets; x++) {
            int i = trainingSetOrder[x];

            //send example to input layer
            for (int z=0; z<inputSize; z++) {
                (*inputLayer)[z]=(*trainingInput)[i][z];
            }

            // Forward pass
            forward(inputLayer,middleLayer,inputMiddleWeights,hiddenLayerBias,middleSize,inputSize);
            forward(middleLayer,outputLayer,middleOutputWeights,outputLayerBias,outputSize,middleSize);

            // Backprop
            for (int j=0; j<outputSize; j++) {
                double errorOutput = ((*trainingOutput)[i][j]-(*outputLayer)[j]);
                (*deltaOutput)[j] = errorOutput*sigmoidDerivative((*outputLayer)[j]);
            }

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
                    (*inputMiddleWeights)[k][j]+=(*inputLayer)[k]*(*deltaHidden)[j]*lr;
                }
            }
        }
        if ((n%100)==0) cout << "Epoch : " << n <<endl;
    }
}

IndexType NeuralNetwork::getInputSize(){
    return inputSize;
}

IndexType NeuralNetwork::getMiddleSize(){
    return middleSize;
}

IndexType NeuralNetwork::getOutputSize(){
    return outputSize;
}

