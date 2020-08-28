#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int start = 0;
    int end = n - 1;
    int ans = 0;
    while (start <= end)
    {
        if (a[start] + a[end] > x)
            end--;
        else
        {
            start++;
            end--;
        }
        ans++;
    }
    cout << ans << endl;
}