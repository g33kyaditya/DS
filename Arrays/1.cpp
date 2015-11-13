//To find common elements in three sorted arrays


#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of elements you want in the arrays: ";
    cin >> n;
    int max = -1;
    int arr1[n],arr2[n],arr3[n];
    cout << "Enter the elements in the first array: ";
    for (int i=0;i<n;i++) {
        cin >> arr1[i];
        if (arr1[i] > max)
            max = arr1[i];
    }

    cout << "Enter the elements in the second array: ";
    for (int i=0;i<n;i++) {
        cin >> arr2[i];
        if (arr2[i] > max)
            max = arr2[i];
    }
    
    cout << "Enter the elements in the third array: ";
    for (int i=0;i<n;i++) {
        cin >> arr3[i];
        if (arr3[i] > max)
            max = arr3[i];
    }
    
    bool boolArr1[max+1] = {false};
    bool boolArr2[max+1] =  {false};
    bool boolArr3[max+1] = {false};

    for (int i=0;i<n;i++) {
        boolArr1[arr1[i]] = true;
        boolArr2[arr2[i]] = true;
        boolArr3[arr3[i]] = true;
    }

    bool arr[max+1] = {false};

    for (int i=0;i<=max;i++) {
        if (boolArr1[i] && boolArr2[i] && boolArr3[i])
            arr[i] = true;
    }

    cout << "The common elements are: ";
    for (int i=0;i<=max;i++) {
        if (arr[i])
            cout << i << " ";
    }
    cout << "\n";
}
