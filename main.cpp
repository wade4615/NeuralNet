#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;

int main(){
    cout << "Neural Net v1.0" << endl;
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
    return 0;
}
