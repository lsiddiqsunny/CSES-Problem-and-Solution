#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long turn = 0;
    long long prev= 0;
    for(int i=0;i<n;i++){
        if(i==0){
            cin>>prev;
            continue;
        }
        long long x;
        cin>>x;
        if(x<prev){
            turn+=(prev-x);
        }else
        prev=x;
    }
    cout<<turn<<endl;;

}