#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int maxi = 1;
    for(int i=0;i<(int)s.size();i++){
        char ch = s[i];
        int co=0;
        while(s[i]==ch){
            co++;
            i++;
        }
        i--;
        maxi = max(maxi,co);

    }
    cout<<maxi<<endl;

}