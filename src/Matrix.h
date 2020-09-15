/*
 * Matrix.h
 *
 *  Created on: Sep 15, 2020
 *      Author: wade4
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <initializer_list>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned IndexType;

double fRand(double fMin, double fMax);

template<class T, IndexType N> class Array;

template<class T, IndexType N, IndexType O>
class Matrix {
    protected:
        IndexType m_rowSize;
        IndexType m_colSize;
        T **elements;
    public:
        Matrix(){
            m_rowSize = 0;
            m_colSize = 0;
            elements = NULL;
        }
        Matrix(double low, double high){
            m_rowSize = N;
            m_colSize = O;
            elements = new T *[m_rowSize];
            for (auto i = 0; i < m_rowSize; i++) {
                elements[i] = new T[m_colSize];
                for (auto j = 0; j < m_colSize; j++) {
                    elements[i][j] = fRand(low, high);
                }
            }
        }
        Matrix(double value){
            m_rowSize = N;
            m_colSize = O;
            elements = new T *[m_rowSize];
            for (auto i = 0; i < m_rowSize; i++) {
                elements[i] = new T[m_colSize];
                for (auto j = 0; j < m_colSize; j++) {
                    elements[i][j] = value;
                }
            }
        }
        Matrix(initializer_list<initializer_list<T>> list){
        	m_rowSize = (int) list.size();
        	m_colSize = (int) (list.begin())->size();
        	elements = new T *[m_rowSize];
        	for (auto i = 0; i < m_rowSize; i++) {
        		elements[i] = new T[m_colSize];
        		for (auto j = 0; j < m_colSize; j++) {
        			elements[i][j] = ((list.begin() + i)->begin())[j];
        		}
        	}
        }
        T *& operator[](const IndexType& index){
            return elements[index];
        }
        IndexType getRows() const{
            return m_rowSize;
        }
        IndexType getCols() const{
            return m_colSize;
        }
        void print(char *text) const{
            cout << text << endl;
            string delimiter = "";
            for (auto i = 0; i < m_rowSize; i++) {
                delimiter = "";
                for (auto j = 0; j < m_colSize; j++) {
                    cout << delimiter << elements[i][j];
                    delimiter = ",";
                }
                cout << std::endl;
            }
        }
		Array<T,N> operator*(Array<T,N> &other) {
		    Array<T,N> *temp = new Array<T,N>(0.0);
		    for (auto i = 0; i < other.getRows(); i++) {
		        double acumulate = 0;
//		        if (bias == NULL)
//		            acumulate = 0;
//		        else
//		            acumulate = (*bias)[i];
		        for (auto j = 0; j < this->m_rowSize; j++) {
		            acumulate += this->elements[i][j] * other[j];
		        }
		        (*temp)[i] += acumulate;
		    }
		    return *temp;
		}
};
#endif /* MATRIX_H_ */
