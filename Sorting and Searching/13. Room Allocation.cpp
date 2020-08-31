#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, {-1, i}});
        v.push_back({b, {1, i}});
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    vector<int> rooms;
    int max_room = 0;
    int taken = 0;
    for (int i = 0; i < 2*n; i++)
    {
        //cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
        if (v[i].second.first == 1)
        {
            rooms.push_back(ans[v[i].second.second]);
        }
        else if (taken == rooms.size())
        {
            max_room++;
            ans[v[i].second.second] = max_room;
        }
        else
        {
            
            ans[v[i].second.second] = rooms[taken++];
        }
    }
    cout << max_room << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}