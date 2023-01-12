#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string &expr)
{
   stack<char> s;
   char ch;
   for (int i = 0; i < expr.length(); i++)
   {
      // for each character in the expression, check conditions
      if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
      { // when it is opening bracket, push into     stack
         s.push(expr[i]);
         continue;
      }

      if (s.empty()) // stack cannot be empty at this stage as the new data is not opening bracket and for that there must be closing bracket in the stack which is not the case here
         return false;

      switch (expr[i])
      {
      case ')': // for closing parenthesis, pop it and check for braces and square brackets
         ch = s.top();
         s.pop();
         if (ch != '(')
            return false;
         break;
      case '}': // for closing braces, pop it and check for parenthesis and square brackets
         ch = s.top();
         s.pop();
         if (ch != '{')
            return false;
         break;
      case ']': // for closing square bracket, pop it and check for braces and parenthesis
         ch = s.top();
         s.pop();
         if (ch != '[')
            return false;
         break;
      }
   }

   return (s.empty()); // when stack is empty, return true
}

int main()
{
   string expr = "[{}(){()}]";
   if (isBalanced(expr))
      cout << "Balanced";
   else
      cout << "Not Balanced";

   return 0;
}