/********************************************************************
 *   Author: Aditya Dev Sharma                                      *
 *   Roll: UE143003                                                 *
 *   Rearrange positive and negative numbers in an array            *
 *   Compiler : GNU GCC                                             *
 *   https://github.com/g33kyaditya/DS/tree/master/Tutorials/Arrays * 
 ********************************************************************/


#include <iostream>
using namespace std;
void swap (int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i=0;i<n;i++)
        cin >> arr[i];
    
    int i=-1;
    for (int j=0;j<n;j++) {
        if (arr[j] < 0 ) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    cout << "The rearranged array is: ";
    for (int i=0;i<n;i++)
        cout << arr[i] << " ";
    
    cout << "\n";
}
