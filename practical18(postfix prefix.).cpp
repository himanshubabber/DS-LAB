#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Function to determine if an operator has higher or equal precedence.
bool hasHigherOrEqualPrecedence(char op1, char op2) {
    if (op1 == '^')
        return true; // Exponentiation has the highest precedence.
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
        return true; // '*' and '/' have higher precedence than '+' and '-'.
    return false;
}

// Function to convert infix to postfix notation.
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else { 
            while (!operators.empty() && operators.top() != '(' && !hasHigherOrEqualPrecedence(c, operators.top())) {
                postfix += operators.top(); 
                operators.pop();
            }
            operators.push(c); 
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

string infixToPrefix(const string& infix) {
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (char& c : reversedInfix) {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    string reversedPostfix = infixToPostfix(reversedInfix);
    reverse(reversedPostfix.begin(), reversedPostfix.end());

    return reversedPostfix;
}

int main() {
    string infixExpression = "a+b*(c^d-e)^(f+g*h)-i";
    string postfixExpression = infixToPostfix(infixExpression);
    string prefixExpression = infixToPrefix(infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Prefix Expression: " << prefixExpression << endl;

    return 0;
}
