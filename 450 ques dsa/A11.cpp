#include <bits/stdc++.h>
using namespace std;
#define m 5
#define n 5
vector<int> findunion(int a[], int b[])
{
    vector<int> u;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            u.push_back(a[i++]);
        else if (a[i] > b[j])
            u.push_back(b[j++]);
        else
        {
            u.push_back(b[j++]);
            i++;
        }
    }
    while (i < m)
        u.push_back(a[i++]);
    while (j < n)
        u.push_back(b[j++]);
    return u;
}
vector<int> find_intersection(int a[], int b[])
{
    vector<int> v;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            v.push_back(b[j]);
            i++;
            j++;
        }
    }
    return v;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};
    cout << "Union is: ";
    vector<int> uni = findunion(a, b);
    for (int &i : uni)
        cout << i << " ";
    cout << endl;
    cout << "Intersection of Sorted Arrays is: ";
    vector<int> inter = find_intersection(a, b);
    for (int &i : inter)
        cout << i << " ";
    return 0;
}