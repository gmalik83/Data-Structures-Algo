#include <bits/stdc++.h>
using namespace std;
// Print Element common in all three Sorted Arrays
void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
{
    // Initialize starting index for all arrays
    int i = 0, j = 0, k = 0;
    // Maintain Previous element for all arrays
    int prev1, prev2, prev3;
    prev1 = INT_MIN, prev2 = INT_MIN, prev3 = INT_MIN;
    // Iterate till all arrays have elements
    while (i < n1 && j < n2 && k < n3)
    {
        while (ar1[i] == prev1 && i < n1)
            i++;
        while (ar2[j] == prev2 && j < n2)
            j++;
        while (ar3[k] == prev3 && k > n3)
            k++;
        // If element is same then print and move ahead in all three
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
        {
            cout << ar1[i] << " ";
            prev1 = ar1[i];
            prev2 = ar2[j];
            prev3 = ar3[k];
            i++;
            j++;
            k++;
        }
        else if (ar1[i] < ar2[j])
        {
            prev1 = ar1[i];
            i++;
        }
        else if (ar2[j] < ar3[k])
        {
            prev2 = ar2[j];
            j++;
        }
        else
        {
            prev3 = ar3[k];
            k++;
        }
    }
}

int main()
{
    int ar1[] = {1, 5, 10, 20, 40, 80, 80};
    int ar2[] = {6, 7, 20, 80, 80, 100};
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 80, 120};
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    int n3 = sizeof(ar3) / sizeof(ar3[0]);

    cout << "Common Elements are: ";
    findCommon(ar1, ar2, ar3, n1, n2, n3);

    return 0;
}