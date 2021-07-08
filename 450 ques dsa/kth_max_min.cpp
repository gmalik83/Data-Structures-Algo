#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    /*
        Approaches :
        1. Sort and return k-1 element from left for min and right for max
        2. Use Min Heap Or Max Heap
        3.Use modified version of quick sort or use map

    */
    sort(arr, arr + n);
 
    // Return k'th element in the sorted array
   cout<<"Kth smallest is: "<<arr[k-1];
    

    return 0;
}