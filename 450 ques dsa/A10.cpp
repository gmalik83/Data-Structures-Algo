#include <bits/stdc++.h>
using namespace std;
#define N 9
void Rearrange(int arr[])
{
    int i = 0;
    int j = N - 1;
    while (true)
    {

        while (i < N && arr[i] < 0)
            i++;

        while (j >= 0 && arr[j] > 0)
            j--;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
            break;
    }
}
void PrintArray(int arr[])
{
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    Rearrange(arr);
    PrintArray(arr);
    return 0;
}