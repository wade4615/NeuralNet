//============================================================================
// Name        : Array.cpp
// Author      : Christopher D. Wade
// Version     :
// Copyright   : 2020 Christopher D. Wade
// Description : implementation for the array class implementation
//============================================================================
#include "Array.h"

Array::Array(Array &other) {
	if (m_matrix != NULL)
		delete[] m_matrix;
	m_size = other.getSize();
	m_matrix = new double[m_size];
	for (auto i = 0; i < m_size; i++) {
		m_matrix[i] = other[i];
	}
}

Array::Array(unsigned size, double low, double high) {
	m_size = size;
	m_matrix = new double[m_size];
	for (auto i = 0; i < m_size; i++) {
		m_matrix[i] = fRand(low, high);
	}
}

Array::Array(unsigned size, double value) {
	m_size = size;
	m_matrix = new double[m_size];
	for (auto i = 0; i < m_size; i++) {
		m_matrix[i] = value;
	}
}

Array::~Array() {
	delete[] m_matrix;
}

Array::Array(initializer_list<double> list) {
	m_size = (int) list.size();
	m_matrix = new double[m_size];
	auto count = 0;
	for (auto element : list) {
		m_matrix[count] = element;
		count++;
	}
}

double& Array::operator[](const IndexType &index) {
	return m_matrix[index];
}

void Array::print(char *text) const {
	cout << text << endl;
	string delimiter = "";
	for (unsigned j = 0; j < m_size; j++) {
		cout << delimiter << m_matrix[j];
		delimiter = ",";
	}
	cout << endl;
}

IndexType Array::getSize() const {
	return m_size;

}
