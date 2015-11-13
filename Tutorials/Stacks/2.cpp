/********************************************************************
 *   Author: Aditya Dev Sharma                                      *
 *   Roll: UE143003                                                 *
 *   Evaluation of a Postfix Expression                             *
 *   Compiler : GNU GCC                                             *
 *   https://github.com/g33kyaditya/DS/tree/master/Tutorials/Stacks * 
 ********************************************************************/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solve (int, char, int);

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

bool isNumber(char ch) {
    if ('0' <= ch && ch <= '9')
        return true;
    else
        return false;
}

int Evaluate(string str) {
    
    stack<int> S;

    for (int i=0;i<str.length();i++) {
        
        if(str[i] == ' ')
            continue;
        
        else if(isOperator(str[i])) {
            int op2 = S.top();
            S.pop();
            int op1 = S.top();
            S.pop();
            int res = solve(op1,str[i],op2);
            S.push(res);
        }
        else if (isNumber(str[i])) {
            int op = 0;
            while (i < str.length() && isNumber(str[i]) ) {
                op = (op*10) + (str[i] - '0');
                i++;
            }
            i--;
            S.push(op);
        }
    }
    return S.top();
}

int solve (int op1, char Operator, int op2 ) {
    if (Operator == '+')    
        return op1+op2;
    
    if (Operator == '-')
        return op1-op2;
    
    if (Operator == '*')
        return op1*op2;
    
    if (Operator == '/')
        return op1/op2;
}


int main() {
    string str;
    cout << "Enter the Postfix Expression: ";
    getline(cin,str);
    int result = Evaluate(str);
    cout << "The value of the expression is: ";
    cout << result << "\n";
    
}
