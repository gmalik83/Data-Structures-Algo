#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

// Find Number of Customer who could not get a computer
/*
        string sequence will be given
        First Entry of character : Coming in Cafe
        Second Entry : Leaving Cafe

        Status
        In Cafe : Using Computer
        In Cafe : Did not get any computer

*/
// Function to return how many person will not get any computer
// N : Total computers in cafe , seq : Customer Entry and Exit Points

int runCustomerSimulation(int n, const char *seq)
{
    /*
    Seen[i] = 0  : Customer is not in the cafe
    Seen[i] = 1  : Customer is in Cafe , but Computer is not assigned
    Seen[i] = 2  : Customer is in Cafe and using Computer
    */
    char seen[MAX_CHAR] = {0};
    // Customer who could not get any computer
    int res = 0;
    int occupied = 0; // Occupied Computers

    // Traverse the input sequence
    for (int i = 0; seq[i]; i++)
    {
        // Find index of current char in seen[]
        int ind = seq[i] - 'A';
        // If first occurence of seq[i]
        if (seen[ind] == 0)
        {
            seen[ind] = 1;
            // If Computer are empty
            if (occupied < n)
            {
                occupied++;
                seen[ind] = 2;
            }
            // Customer cannot get the computer : All computer are occupied
            else
                res++;
        }
        // Second occurence of seq[i]
        else
        {
            // Decrement only if customer is using a computer
            if (seen[ind] == 2)
                occupied--;
            seen[ind] = 0;
        }
    }
    return res;
}

int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;

    return 0;
}