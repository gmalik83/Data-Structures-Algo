#include <bits/stdc++.h>
using namespace std;
// Rearrange Positive and Negative Numbers
/*
    1. Naive Method : Find First Out of Place element and then find element with opposite sign
    and right rotate subarray .
    2.Move negative to end of array and then swap with positive O(N) and O(1)
    
*/
// Function to Rearrange array
void rearrange(int arr[], int n)
{
    int i = 0, j = n - 1;
    // Shift negative values to the end
    while (i < j)
    {
        while (i <= n - 1 && arr[i] > 0)
            i++;
        while (j >= 0 && arr[i] < 0)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    if (i == 0 || i == n)
        return;
    // Start with first positive element at index 0
    int k = 0;
    while (k < n && i < n)
    {
        swap(arr[k], arr[i]);
        i++;
        k = k + 2;
    }
}

// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {2, 3, -4, -1, 6, -9};
    int n = 6;
    cout << "Given array is:";
    printArray(arr, n);
    rearrange(arr, n);
    cout << "Array after rearranging:";
    printArray(arr, n);
    return 0;
}