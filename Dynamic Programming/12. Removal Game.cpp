#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long x[n];
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum += x[i];
    }
    long long dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int l = n - 1; l >= 0; l--)
    {
        for (int r = l; r < n; r++)
        {
            if (l == r)
            {
                dp[l][r] = x[l];
            }
            else
            {
                dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
            }
        }
    }
    cout << (sum + dp[0][n - 1]) / 2 << endl;
}