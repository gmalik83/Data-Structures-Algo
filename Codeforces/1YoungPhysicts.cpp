#include <iostream>

using namespace std;

int main()
{
    int n, x, y, z, xpointsum = 0 , ypointsum = 0, zpointsum = 0;
    cin >> n;

    while (n--)
    {
        cin >> x >> y >> z;
        xpointsum += x;
        ypointsum += y;
        zpointsum += z;
    }

    if (xpointsum == 0 && ypointsum == 0 && zpointsum == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}