#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mod = 1000000007;
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans*=2;
        ans%=mod;
    }
    cout<<ans<<endl;
}