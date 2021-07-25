#include<bits/stdc++.h>
using namespace std;
void sortArray(vector<int> &nums){
   int lo = 0; 
        int hi = nums.size() - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
}
int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Array Before Sorting:\n";
    for(int i = 0 ;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\nSorting the array of 0's 1's and 2's:\n";
    
    sortArray(arr);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    
    return 0;
}