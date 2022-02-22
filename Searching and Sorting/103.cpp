#include <bits/stdc++.h>
using namespace std;

// Search in Sorted and Rotated Array

// Function for Binary Search
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = low + (high - low) / 2;
    if (key == arr[mid])
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, low, (mid - 1), key);

    return binarySearch(arr, (mid + 1), high, key);
}

// Function to return Pivot Element index
int findPivot(int arr[], int low, int high)
{
    if (high < low)
        return -1;
    if (high == low)
        return low;
    int mid = low + (high - low) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}
// Search a key in Sorted Pivoted array
int pivotedBinarySearch(int arr[], int n, int key)
{
    // Find Pivot element index : Next element will be smaller to pivot
    int pivot = findPivot(arr, 0, n - 1);
    // If pivot is not found , then array is not rotated
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);
    // If pivot is found , First compare with pivot and then search for other subarrays
    if (arr[pivot] == key)
        return pivot;

    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);
    return binarySearch(arr, pivot + 1, n - 1, key);
}

int main()
{
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int key = 3;

    // Function calling
    cout << "Index of the element is : "
         << pivotedBinarySearch(arr1, n, key);

    return 0;
}