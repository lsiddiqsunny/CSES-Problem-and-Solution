#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long sum = n*(n+1);
    sum/=2;
    for(int i=1;i<n;i++){
        long long x;
        cin>>x;
        sum-=x;
    }
    cout<<sum<<endl;

}