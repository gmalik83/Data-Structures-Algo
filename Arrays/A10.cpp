#include <bits/stdc++.h>
using namespace std;

// Sort array of Positive and Negative . Order is not important
void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        // If Element is Negative
        if (arr[i] < 0)
        {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}
// Two Pointer Approach
/*  Conditions :  Left and Right Pointer
    1.If Left and Right is negative , then Increment Left
    2.If Left is Positive and Right is Negative , Swap them and incr(Left) and decr(Right)
    3.If Left is Positive and Right is also Positive , then decr(Right)
    4. Repeat 1,2,3 Until Left<=Right
*/
void twoPointer(int arr[], int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (arr[left] < 0 && arr[right] < 0)
            left++;
        else if (arr[left] > 0 && arr[right] < 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        else if (arr[left] > 0 && arr[right] > 0)
            right--;
        else
        {
            left++;
            right--;
        }
    }
}
// Printing the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    /*   Use Partition Process for QuickSort to sort
        USe Two Pointer Approach for Solving 
    
    */
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    // rearrange(arr, n);
    // printArray(arr, n);
    twoPointer(arr, n);
    printArray(arr, n);

    return 0;
}