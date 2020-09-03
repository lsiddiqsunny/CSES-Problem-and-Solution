#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int mod = 1e9 + 7;
    long long int n, m;
    cin >> n >> m;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (a[i-1] == 0 or a[i-1] == j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                if (a[i-1] == 0 or a[i-1] == j)
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    long long int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += (dp[n][i]);
        ans %= mod;
    }
    cout << ans << endl;
}