#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long k;
    cin >> n >> k;
    pair<long long int, int> a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    map<long long int, pair<int, int>> mp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            mp[a[i].first + a[j].first] = {i, j};
    //cout << "here\n";
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long int sum = a[i].first + a[j].first;
            if (mp.find(k - sum) != mp.end())
            {

                pair<int, int> p = mp[k - sum];
                if (p.first != i && p.first != j && p.second != i && p.second != j)
                {
                    cout << a[i].second << " "
                         << a[j].second << " "
                         << a[p.first].second << " "
                         << a[p.second].second;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}