/********************************************************************
 *   Author: Aditya Dev Sharma                                      *
 *   Roll: UE143003                                                 *
 *   Check for balanced parentheses in an expression                *
 *   Compiler : GNU GCC                                             *
 *   https://github.com/g33kyaditya/DS/tree/master/Tutorials/Stacks * 
 ********************************************************************/

#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main() {
    
    cout << "Enter the expression: ";
    string str;
    getline(cin,str);
    stack<char> S;
    for (int i=0;i<str.length();i++) {
        if (str[i] == '(')
            S.push(str[i]);
        else if (str[i] == ')')
            S.pop();
    }
    
    if (!S.empty()) 
        cout << "The expression does not have balanced parentheses\n";
    else
        cout << "The expression contains balanced parentheses\n";
}