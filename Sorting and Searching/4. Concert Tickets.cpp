#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto k = s.lower_bound(x);
        if (k == s.end())
        {
            if (k == s.begin())
            {
                cout << -1 << endl;
                continue;
            }
            k--;
            if (x < *k)
            {
                cout << -1 << endl;
                continue;
            }
            cout << *k << endl;
            s.erase(k);
        }
        else
        {
            if (*k > x && k == s.begin())
            {
                cout << -1 << endl;
                continue;
            }
            if (*k > x)
                k--;
            cout << *k << endl;
            s.erase(k);
        }
    }
}