#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int ans = 0;
    long long int now = 5;
    long long int n;
    cin >> n;
    while (now <= n)
    {
        ans += (int)(n / now);
        now *= 5;
    }
    cout << ans << endl;
}