#include <iostream>
#include "evaluate_postfix.h"
#include "evaluate_prefix.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Prefix\n";
    string expr1 = "* 2 / 3 + 1 2 ";
    Expression exp1(expr1);
    cout  << expr1  << " = "  << exp1.evaluate()  << endl;
    string expr2 = "~ + 2 * ^ 3 3 1";
    Expression exp2(expr2);
    cout  << expr2  << " = "  << exp2.evaluate()  << endl;
    string expr3 = "* 5 - 6 ^ 2 3 ";
    Expression exp3(expr3);
    cout  << expr3  << " = "  << exp3.evaluate()  << endl;
    string expr4 = "~ * ^ 2 3 3 ";
    Expression exp4(expr4);
    cout  << expr4  << " = "  << exp4.evaluate()  << endl;
    cout << "2 -29 -10 -24" << endl;

    cout << "Postfix\n";
    string expr5 = " 2 3 4 * + ";
    IPExpression ipexp1(expr5);
    cout  << expr5  << " = "  << ipexp1.evaluate()  << endl;
    string expr6 = "4 2 5 * + 1 3 2 * + / ";
    IPExpression ipexp2(expr6);
    cout  << expr6  << " = "  << ipexp2.evaluate()  << endl;
    string expr7 = " 5 1 2 4 * + - 2 ^";
    IPExpression ipexp3(expr7);
    cout  << expr7  << " = "  << ipexp3.evaluate()  << endl;
    string expr8 = " 3 2 4 * 1 - +";
    IPExpression ipexp4(expr8);
    cout  << expr8  << " = "  << ipexp4.evaluate()  << endl;
    cout << "14 2 16 10" << endl;
}
