#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int price[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int page[n];
    for (int i = 0; i < n; i++)
    {
        cin >> page[i];
    }
    int dp[n + 1][x + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - price[i - 1] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + page[i - 1]);
            }
        }
    }
    cout<<dp[n][x]<<endl;
}