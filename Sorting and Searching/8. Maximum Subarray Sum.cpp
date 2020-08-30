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
   long long int max_so_far = -1e15, max_ending_here = 0; 
  
    for (int i = 0; i < n; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
   cout<<max_so_far<<endl;
}