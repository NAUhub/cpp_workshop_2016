#ifndef CALCUATOR_H
#define CALCUATOR_H

#include <iostream>
#include <vector>

typedef enum {
    Plus,
    Minus,
    Multiply,
    Divide
} Operation;

double getOperand(int i);

Operation getOperation();

double result(double op1, double op2, Operation op);

void print_result(double res);

#endif // CALCUATOR_H
