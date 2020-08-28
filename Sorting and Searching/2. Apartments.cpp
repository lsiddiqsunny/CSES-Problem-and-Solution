#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    multiset<int> s;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        s.insert(b[i]);
    }
    int ans= 0; 
    for(int i=0;i<n;i++){
        int val=a[i]-k;
        auto it = s.lower_bound(val);
        if(it!=s.end() and *it<= a[i]+k){
            s.erase(it);
            ans++;
        }

    }
    cout<<ans<<endl;
}