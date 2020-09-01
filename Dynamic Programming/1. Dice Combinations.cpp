#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    int table[n+1];
    for (int i = 1; i <= min(n,6); i++)
    {
        table[i] = (1 << (i - 1));
    }
    for (int i = 7; i <= n; i++)
    {
        table[i] = 0;
        for (int j = 1; j <= 6; j++)
        {
            table[i] += table[i - j];
            table[i] %= mod;
        }
    }
    cout << table[n];
}