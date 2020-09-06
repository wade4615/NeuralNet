#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;

int main(){
    cout << "Neural Net v1.0" << endl;
    Matrix input1(2,2);
    input1[0][0] = 1.0;
    input1[0][1] = 1.0;
    input1[1][0] = 1.0;
    input1[1][1] = 1.0;
    input1.show();
    Matrix input2(2,2);
    input2[0][0] = 2.0;
    input2[0][1] = 2.0;
    input2[1][0] = 2.0;
    input2[1][1] = 2.0;
    input2.show();
    Matrix result = input1*input2;
    result.show();
    return 0;
}
