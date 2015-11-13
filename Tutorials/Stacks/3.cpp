/********************************************************************
 *   Author: Aditya Dev Sharma                                      *
 *   Roll: UE143003                                                 *
 *   Reverse an expression using Stack                              *
 *   Compiler : GNU GCC                                             *
 *   https://github.com/g33kyaditya/DS/tree/master/Tutorials/Stacks * 
 ********************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    
    cout << "Enter the string you want to reverse: ";
    string str;
    getline(cin,str);
    
    stack<char> S;
    for (int i=0;i<str.length();i++) 
        S.push(str[i]);
    
    while (!S.empty()) {
        cout << S.top();
        S.pop();
    }
    
    cout << "\n";
}
