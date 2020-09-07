#include <iostream>
#include "NeuralNetwork.h"

using namespace std;

void test1(){
    Matrix<double> input1(2,2);
    input1[0][0] = 1.0;
    input1[0][1] = 2.0;
    input1[1][0] = 3.0;
    input1[1][1] = 4.0;
    input1.print();

    Matrix<double> input2(2,2);
    input2[0][0] = 1.0;
    input2[0][1] = 2.0;
    input2[1][0] = 3.0;
    input2[1][1] = 4.0;
    input2.print();

    Matrix<double> result1 = input1 * input2;
    result1.print();
    cout << endl;

    Array<double> input3(2);
    input3[0] = 1.0;
    input3[1] = 2.0;
    input3.print();

    Array<double> input4(2);
    input4[0] = 1.0;
    input4[1] = 2.0;
    input4.print();
    cout << endl;

    Matrix<double> input5(2,2);
    input5[0][0] = 1.0;
    input5[0][1] = 2.0;
    input5[1][0] = 3.0;
    input5[1][1] = 4.0;
    input5.print();

    Array<double> input6(2);
    input6[0] = 1.0;
    input6[1] = 2.0;
    input6.print();

    Array<double> result2 = input5 * input6;
    result2.print();
}

int main(){
    cout << "Neural Net v1.0" << endl;
    test1();
    NeuralNetwork net(3,4,1);
    return 0;
}
