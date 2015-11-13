/********************************************************************
 *   Author: Aditya Dev Sharma                                      *
 *   Roll: UE143003                                                 *
 *   Move all zeroes to end of array                                *
 *   Compiler : GNU GCC                                             *
 *   https://github.com/g33kyaditya/DS/tree/master/Tutorials/Arrays * 
 ********************************************************************/

#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    int count = 0;
    cout << "Enter the elements of the array: ";
    for (int i=0;i<size;i++) {
        cin >> arr[i];
    }
    
    int ans[size];
    int k = 0;
    for (int i=0;i<size;i++) {
        if (arr[i] != 0) 
            ans[k++] = arr[i];
        else
            count++;
    }

    while (count--) {
        ans[k++] = 0;   
    }
    
    cout << "The array with zeros at the end is: ";
    for (int i=0;i<size;i++)
        cout << ans[i] << " ";
    cout << "\n";
}
