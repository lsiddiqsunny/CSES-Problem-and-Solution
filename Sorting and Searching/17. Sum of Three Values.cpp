#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long k;
    cin >> n >> k;
    pair<long long int,int> a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second=i+1;
    }
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++)
    {

        int l = i + 1;

        int r = n - 1;
        while (l < r)
        {
            if (a[i].first + a[l].first  + a[r].first  == k)
            {
                cout <<a[i].second<< " " << a[l].second << " " << a[r].second << endl;
                return 0;
            }
            else if (a[i].first  + a[l].first  + a[r].first  < k)
                l++;
            else
                r--;
        }
    }

    cout << "IMPOSSIBLE\n";
}