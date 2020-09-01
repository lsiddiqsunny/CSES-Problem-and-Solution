#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    long long int k;
    cin >> n;
    k = n;
    long long int a[n];
    long long int b[k] = {};
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum += a[i];
        long long mod = sum % k;
        mod += k;
        mod %= k;
        b[mod]++;
    }

    for (int i = 0; i < k; i++)
        if (b[i] > 1)
            ans += (b[i] * (b[i] - 1)) / 2;

    ans += b[0];
    cout << ans << endl;
}