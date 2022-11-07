#include <iostream>

template <typename T = int>
class Calculator
{
public:
    T arg1;
    T arg2;
    char op;
    Calculator() : arg1(), arg2(), op('+') {}
    Calculator(T arg) : arg1(arg), arg2(arg), op('+') {}
    Calculator(T arg1, T arg2) : arg1(arg1), arg2(arg2), op('+') {}
    Calculator(T arg1, T arg2, char op) : arg1(arg1), arg2(arg2), op(op) {}
    T exec()
    {
        switch (op)
        {
            case '+':
                return arg1 + arg2;
            case '-':
                return arg1 - arg2;
            case '*':
                return arg1 * arg2;
            case '/':
                return arg1 / arg2;
        }
    }
};