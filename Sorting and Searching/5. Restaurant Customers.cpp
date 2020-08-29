#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   priority_queue<pair<int,bool> > q;
   for(int i=0;i<n;i++){
       int a,b;
       cin>>a>>b;
       q.push({-a,true});
       q.push({-b,false});
   }
   int ans = INT_MIN;
   int x=0;
   while(!q.empty()){
       x+=q.top().second?1:-1;
       q.pop();
       ans=max(ans,x);
   }
   cout<<ans<<endl;
}