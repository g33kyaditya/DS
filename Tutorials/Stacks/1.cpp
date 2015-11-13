/********************************************************************
 *   Author: Aditya Dev Sharma                                      *
 *   Roll: UE143003                                                 *
 *   Infix to Postfix Conversion using stack                        *
 *   Compiler : GNU GCC                                             *
 *   https://github.com/g33kyaditya/DS/tree/master/Tutorials/Stacks * 
 ********************************************************************/

#include <iostream>
#include <string>

#define MAX 1000000
using namespace std;
char arr[MAX];
int top = -1;

bool isOverflow() {
    return top == 99;
}

bool isEmpty() {
    return top == -1;
}
void push(int item) {
    top++;
    arr[top] = item;
}

char Top () {
    if (isEmpty())
        return '!';

    char ch = arr[top];
    return ch;
}

void pop () {
    top--;
}

int precedenceOfOperator(char ch) {
    if (ch == '^')  return 3;
    else if (ch == '*' || ch == '/')    return 2;
    else if (ch == '+' || ch == '-')    return 1;
    else    return 0;
}

void convert(string str) {
    for (int i=0;i<str.length();i++) {
        if ( (str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z') )   cout << str[i];

        else {
            char incomingOperator = str[i];
            if (isEmpty())
                push(incomingOperator);
            else {
                char topOperator = Top();
                //cout << "Top Operator is = " << topOperator << endl;
                int precedenceOfIncomingOperator = precedenceOfOperator(incomingOperator);
                int precedenceOfTopOperator = precedenceOfOperator(topOperator);
                if (precedenceOfIncomingOperator >= precedenceOfTopOperator)
                    push(incomingOperator);
                else {      //Pop until Stack's top has lower precedence
                    while(1) {
                        cout << topOperator;
                        pop();
                        topOperator = Top();
                        precedenceOfTopOperator = precedenceOfOperator(topOperator);
                        if (precedenceOfIncomingOperator >= precedenceOfTopOperator)
                            break;
                    }
                    push(incomingOperator);
                }
            }
        }
    }
    while (!isEmpty()) {
        char topOperator = Top();
        pop();
        if (topOperator != '!')
            cout << topOperator;
    }
}


int main()
{
    string str;
    cout << "Enter the Infix Expression : ";
    cin >> str;
    str = str + "!";
    convert(str);
    cout << "\n";
    return 0;
}
