#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--){
        int a,b;
        cin>>a>>b;
        int mini = min(a,b);
        int maxi = max(a,b);
        if((a+b)%3==0 and mini*2>=maxi){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}