#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    /* There are 3 approaches 
    1.if n is odd initialize min max as a[0]
    2.if n is even initialize min max as first two elements , set i =2
    3.compare in pairs by divide and conquer
    
    */
    int min = a[0],max=a[0]; 
    for(int i=1;i<n;i++)
    {
        if(a[i]<min)
        min = a[i];
        if(a[i]>max)
        max = a[i];
    }
    cout<<"Minimum in array is "<<min<<" and maximum is "<<max;


    return 0;
}