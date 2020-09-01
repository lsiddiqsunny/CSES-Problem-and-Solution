#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int dp[x + 1];
    for (int i = 0; i <= x; i++)
    {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - c[j] >= 0)
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
                //cout<<dp[i]<<" ";
        }
    }
    if (dp[x] == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[x] << endl;
    }
}