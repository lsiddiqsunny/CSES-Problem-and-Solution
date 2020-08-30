#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   long long int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   sort(a,a+n);
   int mid = a[n/2];
   long long ans=0;
   for(int i=0;i<n;i++){
       ans+=abs(mid-a[i]);
   }
   cout<<ans<<endl;
}