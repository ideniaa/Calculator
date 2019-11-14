#include "Calculator.h"
#include <string>
using namespace std;


Calculator::Calculator(const string s = " ")
{
     expr = s;
}

string Calculator::postfix()
{
     Stack<char> st;                    // empty char stack
     string output = " ";               // empty string to hold postfix output

     const char *cPtr = expr.c_str();   // get pointer to char array

     while (*cPtr != '\0')              // loops char array, ignores spaces.
     {
          if (isdigit(*cPtr))           // checks if char is an int
          {
               while (isdigit(*cPtr))   // while loop in case of double digit num
               {
                    output += *cPtr;    // places int in output
                    cPtr++;
               }
               cPtr--;
               output += " ";           // space between each num
          }
          else if (isOperator(*cPtr))   // checks if char is operator
          {
               while (!st.empty() && st.top() != '(' && prec(st.top()) > prec(*cPtr))
               {   
                    output += st.top(); // places higher precedence in output
                    output += " ";
                    st.pop();           // pops operators off stack
               }
               st.push(*cPtr);          // pushes current operator
          }
          else if (*cPtr == '(')
               st.push(*cPtr);          // push open parenthesis onto stack
          else if (*cPtr == ')')       
          {                             
               while (!st.empty())
               {
                    if (st.top() == '(')
                    {                    // if closing parenthesis
                         st.pop();       //  pop off operators until reach open parenthesis
                         break;
                    }
                    output += st.top();
                    output += " ";
                    st.pop();
               }

          }
          cPtr++;        // go to next char on array
     }

     while (!st.empty())  // pop remaining operators
     {
          output += st.top();
          output += " ";
          st.pop();
     }

     return output;
}

int Calculator::eval()
{
     Stack<int> pt;                     // int stack to hold int operands
     int answer = 0;                    // empty int variable to hold end result

     string e = postfix();           // get postfix string
     const char *iPtr = e.c_str();   // convert postfix string to char array

     while (*iPtr != '\0')              // loop goes through postfix & ignores spaces
     {
          if (isdigit(*iPtr))           // if char is an int push into stack
          {
               string ddigit = " ";     // empty string to hold num
               while (isdigit(*iPtr))   // while loop in case of double digit num
               {
                    ddigit += *iPtr;    // places int in output
                    iPtr++;             // continues to next index to check if double digit num
               }
               iPtr--;                  // restores index
               int temp = stoi(ddigit); // converts string to int
               pt.push(temp);
          }
          else if (isOperator(*iPtr))   // if char is operator
          {
               int second = pt.top();   // get ref to top num & set as second operand
               pt.pop();                
               int first = pt.top();    // get ref to new top num & set as first operand to be eval w/ second
               pt.pop();
               int result = operatorEval(first, second, *iPtr);  // calls function to apply operator to the 2 nums that were popped
               pt.push(result);         // result pushed into stack
          }
          iPtr++;
     }
     answer = pt.top();  // get reference for top num (final answer)
     
     pt.pop();           // pop remaining num
     return answer;      
}

void Calculator::setExpr(const string& s)
{
     expr = s;           // sets infix expression
}

string Calculator::getExpr() const
{
     return expr;        // returns infix expression
}

int Calculator::prec(const char p)  // returns precedence of operator
{
     if (p == '^')
          return 3;
     else if (p == '*' || p == '/')
          return 2;
     else if (p == '+' || p == '-')
          return 1;
     else return -1;
}

bool Calculator::isOperator(const char op)   // returns true if char is operator, else false
{
     if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
          return true;
         
     return false;
}

int Calculator::operatorEval(const int a, const int b, const char op) // evaluates two int accordingly based on operator
{
     if (op == '+')
          return a + b;
     else if (op == '-')
          return a - b;
     else if (op == '^')
          return pow(a, b);
     else if (op == '*')
          return a * b;
     else if (op == '/')
          return a / b;
     else return -1;
}

