#include <iostream>
#include <vector>

#include "NeuralNetwork.h"

using namespace std;

void test1(){
    Matrix input1(2,2,0.5);
    input1[0][0] = 1.0;
    input1[0][1] = 2.0;
    input1[1][0] = 3.0;
    input1[1][1] = 4.0;
    input1.print();
    Matrix input2(2,2,0.5);
    input2[0][0] = 1.0;
    input2[0][1] = 2.0;
    input2[1][0] = 3.0;
    input2[1][1] = 4.0;
    input2.print();
    Matrix result1 = input1 * input2;
    result1.print();
    cout << endl;

    Array input3(2,0.5);
    input3[0] = 1.0;
    input3[1] = 2.0;
    input3.print();
    Array input4(2,0.5);
    input4[0] = 1.0;
    input4[1] = 2.0;
    input4.print();
    cout << endl;

    Matrix input5(2,2,0.5);
    input5[0][0] = 1.0;
    input5[0][1] = 2.0;
    input5[1][0] = 3.0;
    input5[1][1] = 4.0;
    input5.print();
    Array input6(2,0.5);
    input6[0] = 1.0;
    input6[1] = 2.0;
    input6.print();
    Array result2 = input5 * input6;
    result2.print();
}

int main(){
    cout << "Neural Net v1.0" << endl;
    test1();
    NeuralNetwork net(3,4,1);
    return 0;
}
