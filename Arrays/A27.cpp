#include <bits/stdc++.h>
using namespace std;
// Factorial of A large Number

// Maximum Number of digits in Output
#define MAX 500

int multiply(int x, int res[], int res_size);
// Find Factorial and Print them
void factorial(int n)
{
    int res[MAX];
    // Initialize array
    res[0] = 1;
    int res_size = 1;
    // Find Factorial using formula
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);
    // Printing Factorial
    cout << "Factorial Of Given Number is:";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
}
// This Function multiplies x with the number represented by res[]
int multiply(int x, int res[], int res_size)
{
    int carry = 0;
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;
        // Store Last digit of Prod in  res[]
        res[i] = prod % 10;
        // Update carry
        carry = prod / 10;
    }
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

int main()
{
    factorial(100);
    return 0;
}