#include <bits/stdc++.h>
using namespace std;
// Rearrange Positive and Negative Numbers
/*
    1. Naive Method : Find First Out of Place element and then find element with opposite sign
    and right rotate subarray .
    
*/

void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}
// Function to rearrange array according to condition
void rearrange(int arr[], int n)
{
    int outofplace = -1;
    for (int index = 0; index < n; index++)
    {
        if (outofplace >= 0)
        {
            if (((arr[index] >= 0) && (arr[outofplace] < 0)) || ((arr[index] < 0) && (arr[outofplace] >= 0)))
            {
                rightrotate(arr, n, outofplace, index);

                // the new out-of-place entry is now 2 steps
                // ahead
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }
        if (outofplace == -1)
        {
            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index & 0x01))) || ((arr[index] < 0) && (index & 0x01)))
            {
                outofplace = index;
            }
        }
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
    int arr[] = {-5, -2, 5, 2,
                 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, n);

    rearrange(arr, n);

    cout << "Rearranged array is \n";
    printArray(arr, n);

    return 0;

    return 0;
}