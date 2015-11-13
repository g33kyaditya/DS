/**********************************************************
 *   Author: Aditya Dev Sharma                            *
 *   Roll: UE143003                                       *
 *   Find the union and intersection of two usorted arrays*
 *   Compiler : GNU GCC                                   *
 **********************************************************/


#include <iostream>
using namespace std;
int main() {
    int n1,n2;
    cout << "Enter the number of elements in the first array: ";
    cin >> n1;
    cout << "Enter the number of elements in the second array: ";
    cin >> n2;
    int arr1[n1],arr2[n2];
    
    int max1 = -1;
    int max2 = -1;
    cout << "Enter the elements of the first array: ";
    for (int i=0;i<n1;i++) {
        cin >> arr1[i];
        if (arr1[i] > max1)
            max1 = arr1[i];
    }
    
    cout << "Enter the elements of the second array: ";
    for (int i=0;i<n2;i++) {
        cin >> arr2[i];
        if (arr2[i] > max2)
            max2 = arr2[i];
    }
    
    bool arr[n1+n2+1] = {false};
    for (int i=0;i<n1;i++) 
        arr[arr1[i]] = true;

    for (int i=0;i<n2;i++)
        arr[arr2[i]] = true;

    cout << "Union of the two arrays: ";
    for (int i=0;i<=n1+n2;i++) {
        if (arr[i])
            cout << i << " ";
    }
    cout << "\n";
    int max = (max1 > max2) ? max1 : max2;
    bool boolArr1[max+1] = {false};
    bool boolArr2[max+1] = {false};
    for (int i=0;i<n1;i++) {
        boolArr1[arr1[i]] = true;
    }
    for (int i=0;i<n2;i++) {
        boolArr2[arr2[i]] = true;
    }
    
    cout << "Intersection of the two arrays: ";
    for (int i=0;i<=max;i++) {
        if (boolArr1[i] && boolArr2[i])
            cout << i << " ";
    }
    cout << "\n";
}
