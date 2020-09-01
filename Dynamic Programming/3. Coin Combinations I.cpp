#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int  n, x;
    cin >> n >> x;

    int mod = 1e9 + 7;

    long long int c[n];

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        
    }

    vector<long long int> dp(x + 1, 0);
    dp[0] = 1;

    for (long long int i = 1; i <= x; i++)
    {
        //dp[i]=INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i - c[j] >= 0)
                dp[i] += dp[i - c[j]];
            dp[i] %= mod;
        }
    }

    cout << dp[x] << endl;
}