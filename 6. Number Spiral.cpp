#include <bits/stdc++.h>
using namespace std;
int main()
{

    long long t;
    cin >> t;
    while (t--)
    {
        long long y, x;
        cin >> y >> x;
        if (y > x)
        {
            if (y % 2)
            {
                y--;
                cout << y * y + x << "\n";
            }
            else
                cout << y * y - x + 1 << "\n";
        }
        else
        {
            if (!(x % 2))
            {
                x--;
                cout << x * x + y << "\n";
            }
            else
                cout << x * x - y + 1 << "\n";
        }
    }
}