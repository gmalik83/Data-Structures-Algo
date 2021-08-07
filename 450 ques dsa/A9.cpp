#include <bits/stdc++.h>
using namespace std;
#define N 10
// Sort Without using Any Sorting Algorithm
void sortArray012(int a[], int n)
{
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
    while (mid <= hi)
    {
        switch (a[mid])
        {

        case 0:
            swap(a[lo++], a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}
void printArray(int a[])
{
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
}
int main()
{
    int arr[] = {1, 0, 2, 0, 0, 1, 1, 2, 2, 0};
    sortArray012(arr, N);
    printArray(arr);
    return 0;
}