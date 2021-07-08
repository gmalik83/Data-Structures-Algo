#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
void RearrangeTwoPointer(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    while (true) {
        // Loop until arr[i] < 0 and
        // still inside the array
        while (arr[i] < 0 && i < n)
            i++;
 
        // Loop until arr[j] > 0 and
        // still inside the array
        while (arr[j] > 0 && j >= 0)
            j--;
 
        // if i is less than j
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
            break;
    }
}
void RearrangeUsingInsertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
      int  key = arr[i];
        if(key>0) // current element is positive do nothing
        continue;
        int  j = i - 1;
        while (j >= 0 && arr[j] > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }


}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    /*
    1. Apply Partition Process of Quick Sort -----Order of elements does not maintain---------- in these approaches
    2.Using Left and Right Pointer  */

    /* If we want to preserve order of elements
    1. Use Modified Version of Insertion Sort ---Time Complexity : O(n2) 
    2. Optimized Merge Sort 
    3.Two Pointer Algorithm*/
     int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
    printArray(arr,n);
    RearrangeUsingInsertionSort(arr,n);
    printArray(arr,n);
    RearrangeTwoPointer(arr,n);
    printArray(arr,n);
    return 0;
}