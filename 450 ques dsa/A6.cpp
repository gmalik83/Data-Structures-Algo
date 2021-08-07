#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int start = 0, end = 4;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}