#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   vector<pair<int,int> > v;
   for(int i=0;i<n;i++){
       int a,b;
       cin>>a>>b;
       v.push_back({b,a});
   }
   sort(v.begin(),v.end());
   int ans=0;
   int now = 0;
   for(auto x:v){
       //cout<<now<<" "<<x.second<<endl;
       if(x.second>=now){
           now = x.first;
           ans++;

       }
   }
   cout<<ans<<endl;
   
}