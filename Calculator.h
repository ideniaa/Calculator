#pragma once
#include <string>
#include "Stack.h"
using namespace std;

class Calculator
{
private:  
     string expr;                      // variable to hold infix expression
     int prec(const char p);           // returns precedence of operators
     bool isOperator(const char op);   // returns true if string is an operator
     int operatorEval(const int a, const int b, const char op);  // performs operator evaluation & returns result
public:
     Calculator(const string s);	 // constructor
     string postfix();		      // returns postfix expression
     int eval();				 // return result of expression
     void setExpr(const string& s); // receives infix expression as string and stores it
     string getExpr() const;	      // returns infix expression as string
};



