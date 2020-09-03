#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int maxi = n*1000;
    int coin[n];
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    bool dp[n+1][maxi+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=maxi;j++){
            dp[i][j]=dp[i-1][j];
            if(j-coin[i-1]>=0 and dp[i-1][j-coin[i-1]]){
                dp[i][j]=true;
            }
        }
    }
    vector<int>ans;
    for(int i=1;i<=maxi;i++){
        if(dp[n][i]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}