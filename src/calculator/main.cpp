#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "calcuator.h"

int main(int argc, char *argv[]) {

    int a = 5;
    int b = 0b0101;
    int c = 0x0005;

    double v1 = getOperand(1);
    double v2 = getOperand(2);
    Operation op = getOperation();
    double res = result(v1, v2, op);
    print_result(res);

    getchar();

    return 0;
}
