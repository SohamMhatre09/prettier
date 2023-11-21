#include <iostream>
#include <stack>

using namespace std;

int precedence(char op)
{
  switch (op)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

bool checkoperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

bool checkoprand(char ch)
{
  return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

string infixtopostfix(const string &infix)
{
  stack<char> opstack;
  string postfix;

  for (char ch : infix)
  {
    if (checkoprand(ch))
    {
      postfix += ch;
    }
    else if (ch == '(')
    {
      opstack.push(ch);
    }
    else if (ch == ')')
    {
      while (opstack.top() != '(')
      {
        postfix += opstack.top();
        opstack.pop();
      }
      opstack.pop();
    }
    else if (checkoperator(ch))
    {
      while (!opstack.empty() && precedence(ch) <= precedence(opstack.top()))
      {
        postfix += opstack.top();
        opstack.pop();
      }
      opstack.push(ch);
    }
  }

  while (!opstack.empty())
  {
    postfix += opstack.top();
    opstack.pop();
  }

  return postfix;
}

int main()
{
  string infixExpression;
  cout << "Enter infix expression: ";
  // getline(cin, infixExpression);
  cin >> infixExpression;

  string postfixExpression = infixtopostfix(infixExpression);

  cout << "Postfix expression: " << postfixExpression << endl;

  return 0;
}
