#include<bits/stdc++.h>
using namespace std;
bool find_x_in_k_window(int arr[],int x,int k,int n)
{

    int i;
    for (i = 0; i < n; i = i + k) {
 

        int j;
        for (j = 0; j < k; j++)
            if (arr[i + j] == x)
                break;
 
    
        if (j == k)
           return false;
    }
 

    if (i == n)
       return true;
 
    int j;
    for (j=i-k; j<n; j++)
      if (arr[j] == x)
          break;
    if (j == n)
       return false; 
      
    return true;
}
int main()
{
    // Consider Every Segment of K and find if X is Present OR Not in every window. Present - "YES"  Not- "NO"
    int n,x,k;
    cin>>n>>x>>k;
   int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(find_x_in_k_window(arr,x,k,n))
        cout<<"Yes";
    else cout<<"No";
    
    return 0;
}