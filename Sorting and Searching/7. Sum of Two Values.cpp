#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back({x, i + 1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        pair<int, int> x = v[i];
        if (x.first >= k)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        int need = k - x.first;

        if (need <= x.first)
        {
            int lo = 0, hi = i - 1;
            int mid;
            while (lo <= hi)
            {

                mid = (lo + hi) / 2;
                if (v[mid].first == need)
                {
                    cout << v[mid].second << " " << x.second << endl;
                    return 0;
                }
                else if (v[mid].first < need)
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }
        if (need >= x.first)
        {
            //cout << need << endl;
            int lo = i + 1, hi = n - 1;
            int mid;
            while (lo <= hi)
            { //cout<<mid<<endl;
                mid = lo + (hi - lo) / 2;
                if (v[mid].first == need)
                {
                    cout <<  x.second<< " "  << v[mid].second <<endl;
                    return 0;
                }
                else if (v[mid].first < need)
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}