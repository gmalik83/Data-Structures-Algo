#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    // Iterate till all elements are sorted
    while (mid <= high)
    {
        switch (arr[mid])
        {
        // If element is 0
        case 0:
            swap(arr[low++], arr[mid++]);
            break;
        // If element is 1
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high--]);
            break;
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0};
    int n = 6;
    sort012(arr, n);
    printArray(arr, n);
    return 0;
}