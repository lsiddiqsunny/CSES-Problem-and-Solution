#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long k;
    cin>>n>>k;
    long long int a[n];
    long long int ans=0;
    long long int sum=0;
    map<long long int,int>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(sum==k){
            ans++;
        }
        if(mp.find(sum-k)!=mp.end()){
            ans+=mp[sum-k];
        }
        mp[sum]++;
    }
    cout<<ans<<endl;

}