#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int dp[n][n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (s[i][j] == '*')
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 and j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            if (i == 0)
            {
                dp[i][j] = dp[i][j - 1];
                continue;
            }
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}