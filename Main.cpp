#include <iostream>
#include "Calculator.h"
using namespace std;

int main()
{
     string expr;

     cout << "Idenia's Calculator\n";
     cout << "Enter 0 to exit the program. \n\n";

     // ask user to input infix expression
     cout << "Enter an expression: ";
     getline(cin, expr);

     while (expr != "0")
     {
          // create calculator object to perform conversion and eval
          Calculator c1(expr);

          // obtain and print the postfix expr
          cout << "Postfix expression: ";
          cout << c1.postfix();
          cout << endl;

          // obtain and print answer of eval
          cout << "Result: ";
          cout << c1.eval();
          cout << endl << endl;

          // ask user for another expression
          cout << "Enter an expression: ";
          getline(cin, expr);
     }

     cout << "Thanks for using my calculator.\n";

     return 0;
}


