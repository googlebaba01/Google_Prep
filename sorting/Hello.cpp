#include<bits/stdc++.h>
using namespace std;

int main() {
    // Declare an array of integers
    int arr[] = {5, 2, 9, 1, 5, 6};
    
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Sort the array using the sort function from the standard library
    sort(arr, arr + n);
    
    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}