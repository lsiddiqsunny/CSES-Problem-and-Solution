#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<long long int,long long int> > v;
    for(int i=0;i<n;i++){
        long long int x,d;
        cin>>x>>d;
        v.push_back({x,d});

    }
    sort(v.begin(),v.end());
    long long int ans = 0;
    long long int run=0;
    for(int i=0;i<n;i++){
        run+=v[i].first;
        ans+=(v[i].second-run);
    }
    cout<<ans<<endl;
}