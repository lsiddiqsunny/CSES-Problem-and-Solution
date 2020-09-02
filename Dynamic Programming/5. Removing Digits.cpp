#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1,1e9);
    
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        for (int j = 0; j < s.size(); j++)
        {
            dp[i] = min(dp[i], dp[i - (s[j] - '0')] + 1);
        }
    }
    cout << dp[n] << endl;
}