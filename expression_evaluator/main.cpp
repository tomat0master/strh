#include "expression_evaluator.h"
#include <iostream>

void equation(const string &expr) {
    cout << expr << " = ";
    cout << evaluate(expr) << endl;
}

int main() {
    cout << "LEGAL EXAMPLES:" << endl;
    equation("3+4");
    equation("3+-4");
    equation("3+2e2");
    equation("3+2e-4");
    equation("(((3+4)))");
    equation("3*-4");
    equation("4-2");
    equation("2*3");
    equation("8/2");
    equation("(2+3)*4");
    equation("((2+3)*4)-2");
    equation("2+(3*4)-(5/2)");
    equation("-2+2");
    equation("-(2+3)*4");
    equation("-2*-3");
    equation("3.14+2.72");
    equation("2e3+3e2");
    equation("5.1e-2/2");

    cout << "ILLEGAL EXAMPLES:" << endl;
    equation("3+---4");
    equation("3+()4");
    equation("3++4");
    equation("3+(+4)");
    equation("3/0");
    equation("(((3+5))");
    equation("2+*3");
    equation("(2+3");
    equation("2+)3");
    equation("a+b");
    equation("2+");
	equation("a2+3n");

    return 0;
}