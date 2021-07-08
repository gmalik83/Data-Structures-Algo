#include<bits/stdc++.h>
using namespace std;
#define ll long long
// Reverse array Function
void reverseArray(int a[],int start,int end)
{
    int temp;
    while(start<end)
    {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;

    }
}
// Printing Array
void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int n; // Size of Array
    cout<<"Enter Size of Array:";
    cin>>n;
    int a[n]; 
    // input array values 
    for(int i=0;i<n;i++)
        cin>>a[i];
    // Calling Reverse Function
   reverseArray(a,0,n-1);
   // Calling Print Array Function
   printArray(a,n);
    return 0;
}