#include "calcuator.h"

double getOperand(int i) {
    double op;
    std::cout << "Input operand " << i << ": ";
    std::cin >> op;
    return op;
}

Operation getOperation() {
    char op;
    std::cout << "Input operation: ";
    std::cin >> op;
    if (op == '+') {
        return Plus;
    } else if (op == '-') {
        return Minus;
    } else if (op == '*') {
        return Multiply;
    } else if (op == '/') {
        return Divide;
    } else {
        return Plus;
    }
}

double result(double op1, double op2, Operation op) {
    switch (op) {
        case Plus:
            return op1+op2;
        case Minus:
            return op1-op2;
        case Multiply:
            return op1*op2;
        case Divide:
            return op1/op2;
    }
    return 0;
}

void print_result(double res) {
    std::cout << "Result: " << res << std::endl;
}
