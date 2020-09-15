/*
 * Array.h
 *
 *  Created on: Sep 15, 2020
 *      Author: wade4
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "Matrix.h"

template<class T, IndexType N>
class Array : public Matrix<T, N, 1> {
    public:
		Array(){
		}
		Array(double low, double high):Matrix<T,N,1>(low, high) {
		}
		Array(double value):Matrix<T,N,1>(value) {
		}
		Array(initializer_list<T> list){
			this->m_rowSize = (int) list.size();
			this->m_colSize = 1;
			this->elements = new T  *[this->m_rowSize];
			auto count = 0;
			for (auto element : list) {
				this->elements[count] = new T[this->m_colSize];
				this->elements[count][0] = element;
				count++;
			}
		}
		T& operator[](const IndexType &index) {
		   return this->elements[index][0];
		}

};

#endif /* ARRAY_H_ */
