//============================================================================
// Name        : NeuralNetwork.cpp
// Author      : Christopher D. Wade
// Version     :
// Copyright   : 2020 Christopher D. Wade
// Description : implementation for a basic backpropagation net
//============================================================================
#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(IndexType inputSize, IndexType middleSize, IndexType outputSize, IndexType exampleSize) :
		inputSize(inputSize),
		middleSize(middleSize),
		outputSize(outputSize),
		numTrainingSets(exampleSize),
		inputLayer(inputSize, 0.0, 1.0),
		inputMiddleWeights(inputSize, middleSize, 0.0, 1.0),
		middleLayer(middleSize, 0.0, 1.0),
		middleOutputWeights(middleSize, outputSize, 0.0, 1.0),
		outputLayer(outputSize, 0.0, 1.0),
		hiddenLayerBias(middleSize, -1.0),
		outputLayerBias(outputSize, -1.0),
		trainingInput(inputSize, exampleSize, 0.0, 1.0),
		trainingOutput(outputSize, exampleSize, 0.0, 1.0),
		deltaHidden(middleSize, 0.0, 1.0),
		deltaOutput(outputSize, 0.0, 1.0) {
}

NeuralNetwork::~NeuralNetwork() {
}

void NeuralNetwork::shuffle(int *array, IndexType n) {
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

void NeuralNetwork::loadTrainingData(Matrix &input, Matrix &output) {
	numTrainingSets = input.getRows();
	trainingInput = input;
	trainingOutput = output;
}

double NeuralNetwork::sigmoid(double x) {
	return 1 / (1 + exp(-x));
}

double NeuralNetwork::sigmoidDerivative(double x) {
	return sigmoid(x) * (1 - sigmoid(x));
}

Array& NeuralNetwork::sigmoid(Array &layerIn) {
	Array layerOut(layerIn);
	for (auto j = 0; j < layerIn.getSize(); j++) {
		layerOut[j] = sigmoid(layerIn[j]);
	}
	return layerOut;
}

Array& NeuralNetwork::sigmoidDerivative(Array &layerIn) {
	Array layerOut(layerIn);
	for (auto j = 0; j < layerIn.getSize(); j++) {
		layerOut[j] = sigmoidDerivative(layerIn[j]);
	}
	return layerOut;
}

IndexType NeuralNetwork::getInputSize() {
	return inputSize;
}

IndexType NeuralNetwork::getMiddleSize() {
	return middleSize;
}

IndexType NeuralNetwork::getOutputSize() {
	return outputSize;
}

void NeuralNetwork::train(IndexType epochs) {
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
			trainingInput.print("training input");
			trainingOutput.print("training output");

			inputMiddleWeights.print("input middle weights");
			middleOutputWeights.print("middle output weights");

			// Forward pass
			for (auto k = 0; k < inputSize; k++) {
				inputLayer[k] = trainingInput[i][k];
			}

			inputMiddleWeights.setBias(&hiddenLayerBias);
			middleLayer = inputMiddleWeights * inputLayer;
			//middleLayer = sigmoid(middleLayer);
			middleLayer.print("middle layer");

			middleOutputWeights.setBias(&outputLayerBias);
			outputLayer = middleOutputWeights * middleLayer;
			//outputLayer = sigmoid(outputLayer);
			outputLayer.print("output layer");

			// Backprop
			double netError = 0.0;
			for (int j = 0; j < outputSize; j++) {
				double errorOutput = (trainingOutput[i][j] - outputLayer[j]);
				deltaOutput[j] = errorOutput
						* sigmoidDerivative(outputLayer[j]);
				netError += 0.5 * pow(errorOutput, 2);
			}
			deltaOutput.print("delta output layer");
			if ((n % 1000) == 0)
				cout << "network error = " << fixed << setprecision(12)
						<< netError << endl;

			for (int j = 0; j < middleSize; j++) {
				double errorHidden = 0.0f;
				for (int k = 0; k < outputSize; k++) {
					errorHidden += deltaOutput[k] * middleOutputWeights[j][k];
				}
				deltaHidden[j] = errorHidden
						* sigmoidDerivative(middleLayer[j]);
			}
			deltaHidden.print("delta hidden layer");

			for (int j = 0; j < outputSize; j++) {
				outputLayerBias[j] += deltaOutput[j] * lr;
				for (int k = 0; k < middleSize; k++) {
					middleOutputWeights[k][j] += middleLayer[k] * deltaOutput[j]
							* lr;
				}
			}
			middleOutputWeights.print("middle output weights");

			for (int j = 0; j < middleSize; j++) {
				hiddenLayerBias[j] += deltaHidden[j] * lr;
				for (int k = 0; k < inputSize; k++) {
					inputMiddleWeights[k][j] += trainingInput[i][k]
							* deltaHidden[j] * lr;
				}
			}
			inputMiddleWeights.print("input middle weights");
			cout
					<< "------------------------------------------------------------------------------------"
					<< endl;
		}
	}
}

