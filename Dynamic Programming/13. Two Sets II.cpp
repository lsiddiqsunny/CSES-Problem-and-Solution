#include <bits/stdc++.h>
using namespace std;
int main()
{
   int mod = 1e9+7;
   int n;
   cin>>n;
   int sum = (n*(n+1))/2;
   if(sum%2){
       cout<<0<<endl;
       return 0;
   }
   int need = sum/2;
   int dp[n+1][need+1];
   memset(dp,0,sizeof(dp));
   dp[0][0]=1;
   for(int i=1;i<n;i++){
       for(int j=0;j<=need;j++){
           dp[i][j] = dp[i-1][j]+(j-i>=0)*dp[i-1][j-i];
           dp[i][j]%=mod;
       }
   }
   cout<<dp[n-1][need];
}