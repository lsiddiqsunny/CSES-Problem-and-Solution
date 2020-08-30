#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int now;
    for (int i = 0; i < n; i++)
    {
        cin >> now;
        auto it = upper_bound(a.begin(), a.end(), now);
        if (it == a.end())
        {
           // cout<<now<<endl;
            a.push_back(now);
        }
        else
        {
           // cout<<(*it)<<endl;
            *it = now;
        }
    }
    cout << a.size();
}