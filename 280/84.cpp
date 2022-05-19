#include <bits/stdc++.h>
using namespace std;

void productArray(int arr[], int n)
{
    // Base Case
    if (n == 1)
    {
        cout << 0;
        return;
    }
    // Allocate Memory of Left and Right
    int *left = new int[n * sizeof(int)];
    int *right = new int[n * sizeof(int)];

    int *prod = new int[n * sizeof(int)];

    int i, j;
    // Leftmost is always 1
    left[0] = 1;
    // Rightmost is always 1
    right[n - 1] = 1;
    // Construct Left Array
    for (i = 1; i < n; i++)
        left[i] = arr[i - 1] * left[i - 1];
    // Construct Right Array
    for (j = n - 2; j >= 0; j--)
        right[j] = arr[j + 1] * right[j + 1];
    // Construct Product Array Using Left and Right
    for (i = 0; i < n; i++)
        prod[i] = left[i] * right[i];
    // Print Product Array
    for (i = 0; i < n; i++)
        cout << prod[i] << " ";
    return;
}

int main()
{
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The product array is: \n";
    productArray(arr, n);
    return 0;
}